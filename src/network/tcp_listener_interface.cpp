#include "network/tcp_listener_interface.hpp"

using namespace ww;

tcp_listener_interface::tcp_listener_interface(boost::asio::io_context &io_context,
                                               const boost::asio::ip::tcp::endpoint &endpoint
) : m_io_context(io_context),
    m_acceptor(io_context, endpoint) {
    spdlog::debug("TCP server interface constructor");
    spdlog::debug("Port: {}", endpoint.port());
}