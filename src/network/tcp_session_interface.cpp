#include "network/tcp_session_interface.hpp"

using namespace ww;

/**
 * @brief Display a success message.
 */
void tcp_session_interface::handle_write(boost::system::error_code const &error, std::size_t bytes_transferred) {
    spdlog::debug("Write method handler");
    // notify (DATA_SEND, data)
}