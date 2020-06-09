#include "network/tcp_connection.hpp"
#include "rooms/room_interface.hpp"

using namespace ww;

tcp_connection::tcp_connection(boost::asio::ip::tcp::socket socket, room_interface &room) : m_socket(std::move(pSocket)), m_room(room)
{

}
