#ifndef WEREWOLFSERVER_TCP_SESSION_WS_HPP
#define WEREWOLFSERVER_TCP_SESSION_WS_HPP

#include <boost/beast.hpp>

#include "network/tcp_session_interface.hpp"

namespace ww {
    using namespace boost::beast;

    class tcp_session_ws : public tcp_session_interface {
    public:
        tcp_session_ws() = delete;

        tcp_session_ws(boost::asio::ip::tcp::socket &&socket);

        void start() override {}

        void stop() override {}

        void write(std::string const &message) override;

        boost::asio::ip::tcp::socket &socket() override;

    private:
        websocket::stream<tcp_stream> m_websocket;

        void read_header() {}

        void handle_read_header(const boost::system::error_code &, std::size_t) override {}

        void read_body() override {}

        void handle_read_body(const boost::system::error_code &, std::size_t) override {}

        void handle_write() override {}

        void write(const packet&) override {}

    };
}


#endif //WEREWOLFSERVER_TCP_SESSION_WS_HPP
