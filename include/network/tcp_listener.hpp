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

        tcp_listener(io_context &context, endpoint const &ep);

        void run() override;

    private:
        void start_accept();

        void handle_accept(std::shared_ptr<tcp_session_interface>  new_session, boost::system::error_code const& error);
    };
}// namespace ww


#endif//WEREWOLFSERVER_TCP_LISTENER_HPP
