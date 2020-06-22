#include "network/tcp_session.hpp"

using namespace ww;

tcp_session::tcp_session(boost::asio::io_context &context) : m_socket{context} {}

boost::asio::ip::tcp::socket &tcp_session::socket() {
    return m_socket;
}

void tcp_session::start() {
    spdlog::debug("Starting the session");
    write("Début de connexion");
    spdlog::debug("Wrote that sessions started");
    read_header();
    spdlog::debug("Called read_header");
}

/**
 * @brief Start an synchronous operation to read 2 Bytes where the header is encoded
 */
void tcp_session::read_header() {
    boost::asio::async_read(
            m_socket,
            boost::asio::buffer(m_header_buffer),
            boost::asio::transfer_exactly(header_size),
            [self = shared_from_this()](const boost::system::error_code &ec, std::size_t bytes_transferred) {
                self->handle_read_header(ec, bytes_transferred);
            }
    );
}

/**
 * @brief We read the size of the incoming packet and prepare our body buffer to receive it.
 * @param error
 * @param bytes_transferred
 */
void tcp_session::handle_read_header(const boost::system::error_code &error, std::size_t bytes_transferred) {
    spdlog::debug("Packet header received");
    header_size_type size = *reinterpret_cast<header_size_type *>(m_header_buffer.data());
    if (!error) {
        m_packet_size = size;
        spdlog::debug("Packet size: {}", m_packet_size);
        m_header_buffer.fill(char{});
        m_body_buffer.clear();
        m_body_buffer.resize(m_packet_size);
        read_body();
    } else {
        spdlog::error("Error processing header: {}", error.message());
        stop();
    }
}

/**
 * @brief Start an synchronous operation to read the amount of data indicated by the header.
 */
void tcp_session::read_body() {
    boost::asio::async_read(
            m_socket,
            boost::asio::buffer(m_body_buffer),
            boost::asio::transfer_exactly(m_packet_size),
            [self = shared_from_this()](const boost::system::error_code &ec, std::size_t bytes_transferred) {
                self->handle_read_body(ec, bytes_transferred);
            }
    );
}

/**
 * @brief We read the content of the body.
 * @param error
 * @param bytes_transferred
 */
void tcp_session::handle_read_body(const boost::system::error_code &error, std::size_t bytes_transferred) {
    spdlog::debug("Packet body received");
    if (!error) {
        std::string message{m_body_buffer.begin(), m_body_buffer.end()};
        spdlog::debug("Packet body: {}", message);
        // notify(CONNECTION_EVENTS::DATA_RECEIVED, message);
        read_header();
    } else {
        spdlog::error("Error processing packet body: {}", error.message());
        stop();
    }
}

/**
 * @brief Send a formatted packet [HEADER (2 Bytes), STRING].
 * @param message
 */
void tcp_session::write(std::string const &message) {
    spdlog::debug("Write a message");
    packet my_packet{message};

    write(my_packet);
}

void tcp_session::write(packet const& p) {
    spdlog::debug("Write a packet");
    auto payload {p.payload()};
    spdlog::debug("Created the payload to send");
    boost::asio::async_write(
            m_socket,
            boost::asio::buffer(payload),
            [self = shared_from_this(), payload = std::move(&payload)](const boost::system::error_code &ec, std::size_t bytes_transferred) {
                spdlog::debug("Calling write handler");
                self->handle_write();
            }
    );
}

/**
 * @brief Display a success message.
 */
void tcp_session::handle_write() {
    spdlog::debug("Write method handler");
}

/**
 * @brief Free allocated memory.
 */
void tcp_session::stop() {
    // notify(CONNECTION_EVENTS::END);
}
