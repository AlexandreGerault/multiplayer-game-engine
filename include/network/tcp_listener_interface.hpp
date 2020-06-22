#ifndef WEREWOLFSERVER_TCP_LISTENER_INTERFACE_HPP
#define WEREWOLFSERVER_TCP_LISTENER_INTERFACE_HPP

#include <boost/asio.hpp>
#include <unordered_set>

#include "network/tcp_session_interface.hpp"

namespace ww {

    class tcp_listener_interface {
    public:
        tcp_listener_interface() = delete;

        tcp_listener_interface(boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const &ep);

        virtual void run() = 0;

    protected:
        boost::asio::io_context &m_io_context;
        boost::asio::ip::tcp::acceptor m_acceptor;
        std::unordered_set<std::shared_ptr<tcp_session_interface>> m_sessions;
    };
}


#endif //WEREWOLFSERVER_TCP_LISTENER_INTERFACE_HPP
