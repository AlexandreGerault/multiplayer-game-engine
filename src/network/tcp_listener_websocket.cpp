#include "network/tcp_listener_websocket.hpp"

using namespace ww;

tcp_listener_websocket::tcp_listener_websocket(boost::asio::io_context &context, const boost::asio::ip::tcp::endpoint &ep) : tcp_listener_interface{context, ep} {
    spdlog::debug("Websocket server created");
}

void tcp_listener_websocket::run() {
    spdlog::debug("Run websocket server on port {}", m_acceptor.local_endpoint().port());

    start_accept();
}

void tcp_listener_websocket::start_accept() {
    spdlog::debug("Start listening for incoming websocket connection...");
    std::shared_ptr<tcp_session_interface> new_session = std::make_shared<tcp_session_websocket>(m_io_context);

    m_acceptor.async_accept(
            new_session->socket(),
            [this, new_session](boost::system::error_code const &error) {
                handle_accept(new_session, error);
            }
    );
}

void tcp_listener_websocket::handle_accept(std::shared_ptr<tcp_session_interface> new_session,
                                           boost::system::error_code const &error) {
    if (!error) {
        spdlog::debug("New websocket connection accepted");
        m_sessions.insert(new_session);
        spdlog::info("Start the websocket session...");
        new_session->start();
        start_accept();
    } else {
        spdlog::error("[Websocket handle accept] {}", error.message());
    }
    
}