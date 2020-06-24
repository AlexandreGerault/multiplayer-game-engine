#ifndef WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP
#define WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP

#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <spdlog/spdlog.h>

#include "network/packet.hpp"

namespace ww {
    class tcp_session_interface : public std::enable_shared_from_this<tcp_session_interface> {
    public:
        virtual void start() = 0;

        virtual void stop() = 0;

        void write(std::string const &message);

        virtual boost::asio::ip::tcp::socket &socket() = 0;

    protected:
        std::vector<char> m_body_buffer;
        std::array<char, header_size> m_header_buffer;
        header_size_type m_packet_size;

        // Read part is split into two processes:
        // 1. We read the header that contains the size of the incoming packet.
        //    It is coded on 2 Bytes
        // 2. We then read the amount of Bytes announced by the header
        void read_header();

        void handle_read_header(const boost::system::error_code &ec, std::size_t bytes_transferred);

        void read_body();

        void handle_read_body(const boost::system::error_code &ec, std::size_t bytes_transferred);

        void handle_write();

        void write(packet const &p);
    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP
