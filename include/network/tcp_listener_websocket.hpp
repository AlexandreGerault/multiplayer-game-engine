#ifndef MGE_TCP_LISTENER_WEBSOCKET_HPP
#define MGE_TCP_LISTENER_WEBSOCKET_HPP

#include <boost/asio.hpp>

#include "network/tcp_listener_interface.hpp"
#include "tcp_session.hpp"
#include "tcp_session_websocket.hpp"

namespace mge {
    class tcp_listener_websocket : public tcp_listener_interface {
    public:
        tcp_listener_websocket() = delete;

        tcp_listener_websocket(boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const &ep, std::weak_ptr<observer> obs);

        void run() override;

    private:
        void start_accept();

        void handle_accept(std::shared_ptr<tcp_session_interface> new_session,
                           boost::system::error_code const &error);
    };
}


#endif //MGE_TCP_LISTENER_WEBSOCKET_HPP
