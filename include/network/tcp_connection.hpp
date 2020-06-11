#ifndef WEREWOLFSERVER_TCP_CONNECTION_HPP
#define WEREWOLFSERVER_TCP_CONNECTION_HPP

#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <string>
#include <iostream>

namespace ww {
    class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
    public:
        tcp_connection() = delete;
        tcp_connection(boost::asio::io_context &context);

        void start();

        void write(std::string message);

        boost::asio::ip::tcp::socket &socket();

    private:
        boost::asio::ip::tcp::socket m_socket;
        void handle_read();
        void handle_write();
        std::string m_data;
    };
}


#endif //WEREWOLFSERVER_TCP_CONNECTION_HPP
