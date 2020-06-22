#ifndef WEREWOLFSERVER_TCP_SESSION_HTTP_HPP
#define WEREWOLFSERVER_TCP_SESSION_HTTP_HPP

#include <memory>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <spdlog/spdlog.h>

#include "network/tcp_session_ws.hpp"

namespace ww {
    class tcp_listener_ws;

    class tcp_session_http : std::enable_shared_from_this<tcp_session_http> {
    public:
        tcp_session_http() = delete;

        tcp_session_http(boost::asio::ip::tcp::socket sock, tcp_listener_ws const& listener);

        void start();

    private:
        boost::asio::ip::tcp::socket m_socket;
        boost::beast::flat_buffer m_buffer;
        boost::beast::http::request<boost::beast::http::string_body> m_request;
        tcp_listener_ws const& m_listener;

        void handle_read(boost::system::error_code &error, std::size_t);
    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_HTTP_HPP
