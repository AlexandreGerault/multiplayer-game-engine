#include "network/tcp_session_websocket.hpp"

using namespace ww;

tcp_session_websocket::tcp_session_websocket(boost::asio::io_context &context) : m_websocket{context} {

}

boost::asio::ip::tcp::socket &tcp_session_websocket::socket() {
    return m_websocket.next_layer().socket();
}

void tcp_session_websocket::start() {
    spdlog::debug("Starting a websocket session");
    read_header();
}

void tcp_session_websocket::stop() {

}