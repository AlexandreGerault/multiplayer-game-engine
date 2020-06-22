#ifndef WEREWOLFSERVER_TCP_LISTENER_HPP
#define WEREWOLFSERVER_TCP_LISTENER_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <spdlog/spdlog.h>

#include "network/tcp_listener_interface.hpp"
#include "network/tcp_session.hpp"

namespace ww {
    class tcp_listener : public tcp_listener_interface {
    public:
        tcp_listener() = delete;

        tcp_listener(boost::asio::io_context &io_context, boost::asio::ip::tcp::endpoint const &enpoint);

        void run() override;

    private:
        void start_accept();

        void handle_accept(session_ptr new_session, boost::system::error_code const& error);
    };
}// namespace ww


#endif//WEREWOLFSERVER_TCP_LISTENER_HPP
