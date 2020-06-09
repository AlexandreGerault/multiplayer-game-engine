#include <network/tcp_server.hpp>
#include <iostream>

using namespace ww;

tcp_server::tcp_server(boost::asio::io_context& io_context, boost::asio::ip::tcp::endpoint const& endpoint) 
	: m_io_context(io_context), m_acceptor(io_context, endpoint) {
    std::cout << "Serveur créé" << std::endl;
}

void ww::tcp_server::start_accept() {
    std::shared_ptr<tcp_connection> new_connection = std::make_shared<tcp_connection>();
}

void ww::tcp_server::handle_accept(std::shared_ptr<tcp_connection> new_connection, const boost::system::error_code &error) {
    if (!error) {
        m_clients.insert(new_connection);
    }
}
