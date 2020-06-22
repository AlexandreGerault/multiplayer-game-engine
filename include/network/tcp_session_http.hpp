#ifndef WEREWOLFSERVER_TCP_SESSION_HTTP_HPP
#define WEREWOLFSERVER_TCP_SESSION_HTTP_HPP

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "network/tcp_session_interface.hpp"

namespace ww {
    class tcp_session_http {
    public:
        tcp_session_http() = delete;

        tcp_session_http(boost::asio::ip::tcp::socket sock);

        void start();

    private:
        boost::asio::ip::tcp::socket m_socket;
        boost::beast::flat_buffer m_buffer;
        boost::beast::http::request<boost::beast::http::string_body> m_request;

        void read_handle(boost::system::error_code const &error, std::size_t);
    };
}

#endif //WEREWOLFSERVER_TCP_SESSION_HTTP_HPP
