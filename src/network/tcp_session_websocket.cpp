#include "network/tcp_session_websocket.hpp"

using namespace ww;

tcp_session_websocket::tcp_session_websocket(boost::asio::io_context &context) : m_websocket{context},
                                                                                 tcp_session_interface{} {

}

boost::asio::ip::tcp::socket &tcp_session_websocket::socket() {
    return m_websocket.next_layer().socket();
}

void tcp_session_websocket::start() {
    spdlog::debug("Starting a websocket session");
    try {
        m_websocket.accept();
    } catch (boost::system::system_error &ec) {
        spdlog::error("[WS] Failed to ws.accept(): {}", ec.what());
    }
    read();
}

void tcp_session_websocket::stop() {

}

void tcp_session_websocket::write(const std::string &message) {
    std::vector<char> payload{message.begin(), message.end()};

    m_websocket.async_write(
            boost::asio::buffer(payload),
            [self = std::static_pointer_cast<tcp_session_websocket>(shared_from_this()), payload = std::move(payload)]
                    (boost::system::error_code const &error, std::size_t bytes_transferred) {
                self->handle_write(error, bytes_transferred);
            }
    );
}

void tcp_session_websocket::read() {
    m_websocket.async_read(
            m_buffer,
            [self = std::static_pointer_cast<tcp_session_websocket>(shared_from_this())](
                    boost::system::error_code const &error, std::size_t bytes_transferred) {
                self->handle_read(error, bytes_transferred);
            }
    );
}

void tcp_session_websocket::handle_read(const boost::system::error_code &error, std::size_t bytes_transferred) {
    if (!error) {
        std::string message{boost::beast::buffers_to_string(m_buffer.data())};
        spdlog::debug("Websocket message: {}", message);
        m_buffer.consume(m_buffer.size());
        read();
    } else {
        spdlog::error("[WS] Error receiving data: {}", error.message());
        stop();
    }
}