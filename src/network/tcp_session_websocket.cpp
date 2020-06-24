#include "network/tcp_session_websocket.hpp"

using namespace ww;

tcp_session_websocket::tcp_session_websocket(boost::asio::io_context &context) : m_websocket{context}, tcp_session_interface{} {

}

boost::asio::ip::tcp::socket &tcp_session_websocket::socket() {
    return m_websocket.next_layer().socket();
}

void tcp_session_websocket::start() {
    spdlog::debug("Starting a websocket session");
    m_websocket.accept();
    read_header();
}

void tcp_session_websocket::stop() {

}