#ifndef WEREWOLF_SERVER_ROOMS_HPP
#define WEREWOLF_SERVER_ROOMS_HPP

#include <map>
#include <memory>
#include "rooms/room_interface.hpp"
#include "utils/factory.hpp"

namespace ww {
    class server_rooms {
    public:
        server_rooms();

        template<class... Args>
        void create_room(std::string const &type, Args &&... args) {
            auto room = m_room_factory.make(type, args...);
            std::string name = room->name();
            m_rooms.insert({name, std::move(room)});
        }

        void delete_room(std::string const &name);

        void remove_room(std::string const &name);

        void restore_room(std::string const &name);

        void for_each(const std::function<void(const room_interface &)>& my_callback);

    private:
        void initFactory();

        std::map<std::string, std::unique_ptr<room_interface>> m_rooms;
        std::map<std::string, std::unique_ptr<room_interface>> m_removed_rooms;
        factory<room_interface, std::string> m_room_factory;
    };
}// namespace ww


#endif//WEREWOLF_SERVER_ROOMS_HPP
