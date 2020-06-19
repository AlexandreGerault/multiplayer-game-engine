#include "network/tcp_connection.hpp"

using namespace ww;

tcp_connection::tcp_connection(boost::asio::io_context &context) : m_socket{context} {}

boost::asio::ip::tcp::socket &tcp_connection::socket() {
    return m_socket;
}

void tcp_connection::start() {
    write("Début de connexion");
    read_header();
}

/**
 * @brief Start an synchronous operation to read 2 Bytes where the header is encoded
 */
void tcp_connection::read_header() {
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
void tcp_connection::handle_read_header(const boost::system::error_code &error, std::size_t bytes_transferred) {
    std::cout << "En-tête reçu" << std::endl;
    header_size_type size = *reinterpret_cast<header_size_type *>(m_header_buffer.data());
    if (!error) {
        m_packet_size = size;
        std::cout << "Packet size: " << m_packet_size << std::endl;
        m_header_buffer.fill(char{});
        m_body_buffer.clear();
        m_body_buffer.resize(m_packet_size);
        read_body();
    } else {
        std::cout << "Erreurs rencontrées pendant le traitement de l'en-tête" << std::endl;
        std::cout << error.message() << std::endl;
        stop();
    }
}

/**
 * @brief Start an synchronous operation to read the amount of data indicated by the header.
 */
void tcp_connection::read_body() {
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
void tcp_connection::handle_read_body(const boost::system::error_code &error, std::size_t bytes_transferred) {
    std::cout << "Corps de paquet reçu" << std::endl;
    if (!error) {
        std::cout << "Pas d'erreur" << std::endl;
        std::string message{m_body_buffer.begin(), m_body_buffer.end()};
        std::cout << message << std::endl;
        // notify(CONNECTION_EVENTS::DATA_RECEIVED, message);
        read_header();
    } else {
        std::cout << "Erreurs rencontrées pendant le traitement du corps du paquet" << std::endl;
        std::cout << error.message() << std::endl;
        stop();
    }
}

/**
 * @brief Send a formatted packet [HEADER (2 Bytes), STRING].
 * @param message
 */
void tcp_connection::write(std::string const &message) {
    packet my_packet{message};

    write(my_packet);
}

void tcp_connection::write(packet const& p) {
    auto payload {p.payload()};
    boost::asio::async_write(
            m_socket,
            boost::asio::buffer(payload),
            [self = shared_from_this(), payload = std::move(payload)](const boost::system::error_code &ec, std::size_t bytes_transferred) {
                self->handle_write();
            }
    );
}

/**
 * @brief Display a success message.
 */
void tcp_connection::handle_write() {
    std::cout << "Message envoyé" << std::endl;
}

/**
 * @brief Free allocated memory.
 */
void tcp_connection::stop() {
    // notify(CONNECTION_EVENTS::END);
}
