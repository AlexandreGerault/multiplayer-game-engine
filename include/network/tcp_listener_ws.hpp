#ifndef WEREWOLFSERVER_TCP_LISTENER_WS_HPP
#define WEREWOLFSERVER_TCP_LISTENER_WS_HPP

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "network/tcp_listener_interface.hpp"

namespace ww {
    class tcp_session_http;

    class tcp_listener_ws : public tcp_listener_interface {
    public:
        tcp_listener_ws() = delete;

        tcp_listener_ws(boost::asio::io_context &io_context, boost::asio::ip::tcp::endpoint const &endpoint);

        void run() override;

        void add(session_ptr ws_session, boost::system::error_code const& error);

    private:
        boost::asio::ip::tcp::socket m_socket;

        void start_accept() override;

        void handle_accept(const boost::system::error_code &error);

        void handle_accept(session_ptr new_connection, boost::system::error_code const& error) override;
    };
}

#endif //WEREWOLFSERVER_TCP_LISTENER_WS_HPP
