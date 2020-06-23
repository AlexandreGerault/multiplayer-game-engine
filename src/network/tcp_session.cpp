#include "network/tcp_session.hpp"

using namespace ww;

tcp_session::tcp_session(boost::asio::io_context &context) : m_socket{context} {}

boost::asio::ip::tcp::socket &tcp_session::socket() {
    return m_socket;
}

void tcp_session::start() {
    spdlog::debug("Starting a TCP session");
    write("Début de connexion");
    read_header();
}


/**
 * @brief Free allocated memory.
 */
void tcp_session::stop() {
    // notify(CONNECTION_EVENTS::END);
}
