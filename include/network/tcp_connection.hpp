#ifndef WEREWOLFSERVER_TCP_CONNECTION_HPP
#define WEREWOLFSERVER_TCP_CONNECTION_HPP

#include <memory>
#include <boost/asio.hpp>


namespace ww {
    class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
    public:
        tcp_connection() = delete;
        tcp_connection(boost::asio::io_context &context);

        boost::asio::ip::tcp::socket &socket();

    private:
        boost::asio::ip::tcp::socket m_socket;
    };
}


#endif //WEREWOLFSERVER_TCP_CONNECTION_HPP
