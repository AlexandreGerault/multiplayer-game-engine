#ifndef WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP
#define WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>

#include "network/tcp_session_interface.hpp"

namespace ww {
    class tcp_session_websocket : public tcp_session_interface {
    public:
        tcp_session_websocket() = delete;

        tcp_session_websocket(boost::asio::io_context &context);

        void start() override;

        void stop() override;

        boost::asio::ip::tcp::socket &socket() override;

        void write(std::string const &message) override;

    private:
        boost::beast::websocket::stream<boost::beast::tcp_stream> m_websocket;
        boost::beast::flat_buffer m_buffer;

        void read();

        void handle_read(const boost::system::error_code &error, std::size_t bytes_transferred);
    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_WEBSOCKET_HPP
