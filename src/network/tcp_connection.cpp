#include "network/tcp_connection.hpp"

using namespace ww;

tcp_connection::tcp_connection(boost::asio::io_context &context) : m_socket(context) {}

boost::asio::ip::tcp::socket &tcp_connection::socket() {
    return m_socket;
}