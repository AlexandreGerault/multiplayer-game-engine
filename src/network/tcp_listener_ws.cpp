#include "network/tcp_listener_ws.hpp"

using namespace ww;

tcp_listener_ws::tcp_listener_ws(boost::asio::io_context &io_context, const boost::asio::ip::tcp::endpoint &endpoint)
        : tcp_listener_interface{io_context, endpoint} {
    spdlog::debug("Websocket server created");
    spdlog::debug("Start listening websocket connections");
    m_acceptor.listen();
}

void tcp_listener_ws::run() {
    start_accept();
}

void tcp_listener_ws::start_accept() {
    spdlog::debug("Start listening for incoming HTTP request (websocket upgrade demand) connection...");

    m_acceptor.async_accept(
            m_socket,
            [this] () {
                handle_accept(const boost::system::error_code ec);
            })
}

void tcp_listener_ws::handle_accept(const boost::system::error_code &error) {
    if (!error) {
        auto http_connection = std::make_shared<http_session>(std::move(m_socket));
        http_connection->start();
    }
}

//void tcp_listener_ws::handle_accept(session_ptr new_connection, const boost::system::error_code &error) {
//    if (!error) {
//        spdlog::info("New HTTP (websocket upgrade demand) connection!");
//        m_clients.insert(new_connection);
//        new_connection->start();
//        start_accept();
//    }
//}
