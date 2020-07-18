#ifndef MGE_TCP_LISTENER_INTERFACE_HPP
#define MGE_TCP_LISTENER_INTERFACE_HPP

#include <boost/asio.hpp>
#include <unordered_set>
#include <memory>

#include "network/tcp_session_interface.hpp"
#include "utils/observer.hpp"

namespace mge {

    class tcp_listener_interface {
    public:
        tcp_listener_interface() = delete;

        tcp_listener_interface(boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const &ep, std::weak_ptr<observer> obs);

        virtual void run() = 0;

    protected:
        std::weak_ptr<observer> m_command_observer;
        boost::asio::io_context &m_io_context;
        boost::asio::ip::tcp::acceptor m_acceptor;
        std::unordered_set<std::shared_ptr<tcp_session_interface>> m_sessions;
    };
}


#endif //MGE_TCP_LISTENER_INTERFACE_HPP
