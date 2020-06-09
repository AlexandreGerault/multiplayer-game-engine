#ifndef WEREWOLFSERVER_TCP_CONNECTION_HPP
#define WEREWOLFSERVER_TCP_CONNECTION_HPP

#include <memory>
#include <boost/asio/ip/tcp.hpp>


namespace ww {
    class room_interface;

    class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
    public:
        tcp_connection(boost::asio::ip::tcp::socket socket, room_interface &room);

    private:
        boost::asio::ip::tcp::socket m_socket;
        room_interface &m_room;
    };
}


#endif //WEREWOLFSERVER_TCP_CONNECTION_HPP
