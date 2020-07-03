#ifndef WEREWOLFSERVER_TCP_LISTENER_HPP
#define WEREWOLFSERVER_TCP_LISTENER_HPP

#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

#include "network/tcp_listener_interface.hpp"
#include "network/tcp_session.hpp"

namespace ww {
    class tcp_listener : public tcp_listener_interface {
    public:
        tcp_listener() = delete;

        tcp_listener(boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const &ep, std::weak_ptr<observer> obs);

        void run() override;

    private:
        void start_accept();

        void handle_accept(std::shared_ptr<tcp_session_interface>  new_session, boost::system::error_code const& error);
    };
} // namespace ww


#endif//WEREWOLFSERVER_TCP_LISTENER_HPP
