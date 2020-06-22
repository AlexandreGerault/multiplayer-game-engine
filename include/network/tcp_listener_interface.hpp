#ifndef WEREWOLFSERVER_TCP_LISTENER_INTERFACE_HPP
#define WEREWOLFSERVER_TCP_LISTENER_INTERFACE_HPP

#include <boost/asio.hpp>
#include <unordered_set>
#include <memory>
#include <spdlog/spdlog.h>

#include "network/tcp_session_interface.hpp"

namespace ww {
    typedef std::shared_ptr<tcp_session_interface> session_ptr;

    class tcp_listener_interface {
    public:
        tcp_listener_interface() = delete;

        tcp_listener_interface(boost::asio::io_context &io_context, boost::asio::ip::tcp::endpoint const &endpoint);

        virtual void run() = 0;

    protected:
        boost::asio::io_context &m_io_context;
        boost::asio::ip::tcp::acceptor m_acceptor;
        std::unordered_set<session_ptr> m_clients;

        virtual void start_accept() = 0;

        virtual void handle_accept(session_ptr new_connection, const boost::system::error_code &error) = 0;
    };
} //namespace ww



#endif //WEREWOLFSERVER_TCP_LISTENER_INTERFACE_HPP
