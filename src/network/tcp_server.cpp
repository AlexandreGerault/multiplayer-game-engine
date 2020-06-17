#include "network/tcp_server.hpp"
#include <iostream>

using namespace ww;

tcp_server::tcp_server(boost::asio::io_context& io_context, boost::asio::ip::tcp::endpoint const& endpoint) 
	: m_io_context(io_context), m_acceptor(io_context, endpoint) {
    std::cout << "Serveur créé" << std::endl;
}

/**
 * @brief start the server events loop.
 */
void tcp_server::run() {
    std::cout << "Début d'écoute des connexions" << std::endl;
    start_accept();

    std::cout << "io_context::run();" << std::endl;
    m_io_context.run();
}

/**
 * @brief we start to listen for a new connection.
 */
void tcp_server::start_accept() {
    std::cout << "En attente de connexion..." << std::endl;
    std::shared_ptr<tcp_connection> new_connection = std::make_shared<tcp_connection>(m_io_context);

    m_acceptor.async_accept(
        new_connection->socket(),
        boost::bind(&tcp_server::handle_accept, this, new_connection, boost::asio::placeholders::error)
    );
}

/**
 * @brief add the new connection to the set then listen for a new connection again (to avoid the server to stop).
 *
 * @param new_connection
 * @param error
 */
void tcp_server::handle_accept(std::shared_ptr<tcp_connection> new_connection, const boost::system::error_code &error) {
    if (!error) {
        std::cout << "Nouvelle connexion acceptée." << std::endl;
        m_clients.insert(new_connection);
        new_connection->start();
        start_accept();
    }
}
