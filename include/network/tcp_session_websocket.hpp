#ifndef WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP
#define WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>

#include "network/tcp_session_interface.hpp"

namespace ww {
    class tcp_session_websocket : public tcp_session_interface {
    public:
        tcp_session_websocket() = delete;

        tcp_session_websocket(boost::asio::io_context &context);

        void start() override;

        void stop() override;

        boost::asio::ip::tcp::socket &socket() override;

    private:
        boost::beast::websocket::stream<boost::beast::tcp_stream> m_websocket;
    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP
