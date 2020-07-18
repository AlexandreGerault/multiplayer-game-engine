#ifndef MGE_TCP_SESSION_INTERFACE_HPP
#define MGE_TCP_SESSION_INTERFACE_HPP

#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <spdlog/spdlog.h>

#include "network/data_received_event.hpp"
#include "network/packet.hpp"
#include "utils/observable.hpp"

namespace mge {
    class tcp_session_interface : public std::enable_shared_from_this<tcp_session_interface>, public observable {
    public:
        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void write(std::string const &message) = 0;

        virtual boost::asio::ip::tcp::socket &socket() = 0;

    protected:
        virtual void handle_write(boost::system::error_code const &error, std::size_t bytes_transferred);
    };
}

#endif //MGE_TCP_SESSION_INTERFACE_HPP
