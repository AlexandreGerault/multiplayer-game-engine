#ifndef WEREWOLFSERVER_TCP_SERVER_HPP
#define WEREWOLFSERVER_TCP_SERVER_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <unordered_set>
#include <memory>
#include "network/tcp_connection.hpp"

namespace ww {
    class tcp_server {
    public:
        tcp_server() = delete;
        tcp_server(boost::asio::io_context &io_context, boost::asio::ip::tcp::endpoint const &enpoint);
        void run();

    private:
        boost::asio::io_context& m_io_context;
        boost::asio::ip::tcp::acceptor m_acceptor;
        std::unordered_set<std::shared_ptr<tcp_connection>> m_clients;

        void start_accept();
        void handle_accept(std::shared_ptr<tcp_connection> new_connection, const boost::system::error_code &error);
    };
}// namespace ww


#endif//WEREWOLFSERVER_TCP_SERVER_HPP
