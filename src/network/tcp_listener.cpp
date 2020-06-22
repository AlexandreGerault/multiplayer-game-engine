#include "network/tcp_listener.hpp"
#include <iostream>

using namespace ww;

tcp_listener::tcp_listener(boost::asio::io_context &io_context, boost::asio::ip::tcp::endpoint const &endpoint)
        : tcp_listener_interface{io_context, endpoint} {
    spdlog::debug("TCP server created");
}

/**
 * @brief start the server events loop.
 */
void tcp_listener::run() {
    spdlog::debug("Run server");
    start_accept();
}

/**
 * @brief we start to listen for a new connection.
 */
void tcp_listener::start_accept() {
    spdlog::debug("Start listening for incoming TCP connection...");
    session_ptr new_connection = std::make_shared<tcp_session>(m_io_context);
    spdlog::debug("New TCP connection pointer created.");

    m_acceptor.async_accept(
            new_connection->socket(),
            boost::bind(&tcp_listener::handle_accept, this, new_connection, boost::asio::placeholders::error)
    );
}

/**
 * @brief add the new connection to the set then listen for a new connection again (to avoid the server to stop).
 *
 * @param new_connection
 * @param error
 */
void tcp_listener::handle_accept(session_ptr new_connection, const boost::system::error_code &error) {
    if (!error) {
        spdlog::info("New TCP connection!");
        m_clients.insert(new_connection);
        new_connection->start();
        start_accept();
    }
}
