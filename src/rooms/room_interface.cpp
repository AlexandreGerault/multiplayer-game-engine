#include "network/tcp_connection.hpp"
#include "rooms/room_interface.hpp"

using namespace ww;

room_interface::room_interface(const std::string &name) : m_state(room_state::lobby), m_name(name),
                                                          m_config(name + ".config") {}

void room_interface::join(std::shared_ptr<tcp_connection> client) {
    m_clients.insert(client);
}

void room_interface::leave(std::shared_ptr<tcp_connection> client) {
    m_clients.erase(client);
}
