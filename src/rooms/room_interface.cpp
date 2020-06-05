#include <rooms/room_interface.hpp>

using namespace ww;

room_interface::room_interface(const std::string &name) : m_state(room_state::lobby), m_name(name), m_config(name + ".config") {}