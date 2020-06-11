#include "network/tcp_connection.hpp"

using namespace ww;

tcp_connection::tcp_connection(boost::asio::io_context &context) : m_socket(context) {}

boost::asio::ip::tcp::socket &tcp_connection::socket() {
    return m_socket;
}

void tcp_connection::start() {
//    boost::asio::async_read(
//            m_socket,
//            boost::asio::buffer(),
//            boost::bind(&tcp_connection::handle_read, this)
//            );
    write("Début de connexion");
}

void tcp_connection::handle_read() {

}

void tcp_connection::write(std::string message) {
    boost::asio::async_write(
            m_socket,
            boost::asio::buffer(message, message.size()),
            boost::bind(&tcp_connection::handle_write, this)
            );
}

void tcp_connection::handle_write() {
    std::cout << "Message envoyé" << std::endl;
}