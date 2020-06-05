#include <rooms/server_rooms.hpp>
#include <rooms/text_room.hpp>
#include <rooms/voice_room.hpp>

using namespace ww;

server_rooms::server_rooms() {
    // TODO: Load rooms from files (serialization)
    initFactory();
}

/**
 * Add all the possible rooms to the factory.
 */
void server_rooms::initFactory() {
    m_room_factory.registers("text_room", [](std::string const &name) -> std::unique_ptr<room_interface> {
        return std::make_unique<text_room>(name);
    });
    m_room_factory.registers("voice_room", [](std::string const &name) -> std::unique_ptr<room_interface> {
        return std::make_unique<voice_room>(name);
    });
}

/**
 * Delete permanently a room from the memory.
 *
 * @param name
 */
void server_rooms::delete_room(std::string const &name) {
    m_rooms.erase(name);
}

/**
 * Move the room to the removed rooms map (aka not accessible rooms).
 *
 * @param name
 */
void server_rooms::remove_room(std::string const &name) {
    m_removed_rooms.insert({name, std::move(m_rooms.find(name)->second)});
    m_rooms.erase(name);
}

/**
 * Restore a room that has been removed (aka accessible room).
 *
 * @param name
 */
void server_rooms::restore_room(std::string const &name) {
    m_rooms.insert({name, std::move(m_removed_rooms.find(name)->second)});
    m_removed_rooms.erase(name);
}

/**
 * Implementation of a foreach loop but preventing rooms to be copied.
 *
 * @param my_callback
 */
void server_rooms::for_each(const std::function<void(const room_interface &)>& my_callback) {
    for (const auto &[key, value]: m_rooms) {
        my_callback(*value);
    }
}
