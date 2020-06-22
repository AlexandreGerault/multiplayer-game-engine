#ifndef WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP
#define WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP

#include <string>
#include <boost/asio.hpp>

#include "network/packet.hpp"

namespace ww {
    class tcp_session_interface {
    public:
        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void write(std::string const &message) = 0;

        virtual boost::asio::ip::tcp::socket &socket() = 0;

    private:
        // Read part is split into two processes:
        // 1. We read the header that contains the size of the incoming packet.
        //    It is coded on 2 Bytes
        // 2. We then read the amount of Bytes announced by the header
        virtual void read_header() = 0;

        virtual void handle_read_header(const boost::system::error_code &ec, std::size_t bytes_transferred) = 0;

        virtual void read_body() = 0;

        virtual void handle_read_body(const boost::system::error_code &ec, std::size_t bytes_transferred) = 0;

        virtual void handle_write() = 0;

        virtual void write(packet const &p) = 0;
    };
}
#endif //WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP
