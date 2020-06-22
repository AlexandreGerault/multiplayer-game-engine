#include "network/tcp_session_http.hpp"
#include "network/tcp_listener_ws.hpp"

using namespace ww;

tcp_session_http::tcp_session_http(boost::asio::ip::tcp::socket sock, tcp_listener_ws const &l) : m_socket{std::move(sock)}, m_listener {l} {}

void tcp_session_http::start() {
    boost::beast::http::async_read(
            m_socket,
            m_buffer,
            m_request,
            [self = shared_from_this()](boost::system::error_code error, std::size_t bytes) {
                self->handle_read(error, bytes);
            });
}

void tcp_session_http::handle_read(boost::system::error_code &error, std::size_t) {
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
