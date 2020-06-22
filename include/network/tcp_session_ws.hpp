#ifndef WEREWOLFSERVER_TCP_SESSION_WS_HPP
#define WEREWOLFSERVER_TCP_SESSION_WS_HPP

#include <boost/beast.hpp>

#include "network/tcp_session_interface.hpp"

namespace ww {
    using namespace boost::beast;

    class tcp_session_ws : public tcp_session_interface {
    public:
        tcp_session_ws() = delete;

        tcp_session_ws(tcp::socket&& socket);

        void run() override;

        void write(std::string const &message) override;

        boost::asio::ip::tcp::socket &socket() override;
    private:
        websocket::stream<tcp_stream> m_websocket;
    };
}


#endif //WEREWOLFSERVER_TCP_SESSION_WS_HPP