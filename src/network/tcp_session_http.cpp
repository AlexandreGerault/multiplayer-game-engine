#include "network/tcp_session_http.hpp"

using namespace ww;

tcp_session_http::tcp_session_http(boost::asio::ip::tcp::socket sock) {}

void tcp_session_http::start() {
    http::async_read(
            m_socket,
            m_buffer,
            m_request,
            [self = shared_from_this()](boost::system::error_code error, std::size_t bytes) {
                self->handle_read(error, bytes);
            });
}

void tcp_session_http::read_handle(boost::system::error_code const &error, std::size_t) {
    if (error == boost::beast::http::error::end_of_stream) {
        m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send, error);
        return;
    }

    if (!error) {
        if (boost::beast::websocket::is_upgrade(m_request)) {
            spdlog::debug("Websocket upgrade demand...");
            auto ws_session = std::make_shared<tcp_session_ws>(std::move(m_socket));

            return;
        }
    }

    spdlog::debug("Received a normal HTTP request... Abort the request and the HTTP session.");

    return;
}