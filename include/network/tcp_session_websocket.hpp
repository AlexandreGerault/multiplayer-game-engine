#ifndef WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP
#define WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <memory>

#include "network/tcp_session_interface.hpp"

namespace ww {
    class tcp_session_websocket : public tcp_session_interface, std::enable_shared_from_this<tcp_session_websocket> {
    public:
        tcp_session_websocket() = delete;

        tcp_session_websocket(boost::asio::io_context &context);

        void start() override;

        void stop() override;

        void write(std::string const &message) override;

        boost::asio::ip::tcp::socket &socket() override;

    private:

    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP
