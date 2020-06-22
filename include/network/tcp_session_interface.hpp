#ifndef WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP
#define WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP

#include <boost/asio.hpp>
#include <string>

namespace ww {
    class tcp_session_interface {
    public:
        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void write(std::string const &message) = 0;

        virtual boost::asio::ip::tcp::socket &socket() = 0;
    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_INTERFACE_HPP
