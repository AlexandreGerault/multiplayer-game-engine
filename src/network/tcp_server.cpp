#include "network/tcp_server.hpp"
#include <iostream>

using namespace ww;

tcp_server::tcp_server(boost::asio::io_context& io_context, boost::asio::ip::tcp::endpoint const& endpoint) 
	: m_io_context(io_context), m_acceptor(io_context, endpoint) {
    std::cout << "Serveur cr��" << std::endl;

    std::cout << "io_context::run();" << std::endl;
    m_io_context.run();
}

void tcp_server::start_accept() {
    std::shared_ptr<tcp_connection> new_connection = std::make_shared<tcp_connection>(m_io_context);

    m_acceptor.async_accept(
        new_connection->socket(),
        boost::bind(&tcp_server::handle_accept, this, new_connection, boost::asio::placeholders::error)
    );
}

void tcp_server::handle_accept(std::shared_ptr<tcp_connection> new_connection, const boost::system::error_code &error) {
    if (!error) {
        m_clients.insert(new_connection);
    }
}
