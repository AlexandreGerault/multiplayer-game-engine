#ifndef WEREWOLFSERVER_TCP_SESSION_HPP
#define WEREWOLFSERVER_TCP_SESSION_HPP

#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <cstdint>
#include <spdlog/spdlog.h>

#include "network/tcp_session_interface.hpp"

namespace ww {
    /**
     * @brief Send and receive data using TCP.
     * Each packet follows the following format: {[HEADER (2 BYTES)][CONTENT {String} (SIZE CODED IN HEADER)].}
     */
    class tcp_session : public tcp_session_interface {
    public:
        tcp_session() = delete;

        tcp_session(boost::asio::io_context &context);

        void start() override;

        void stop() override;

        boost::asio::ip::tcp::socket &socket() override;

    private:


        boost::asio::ip::tcp::socket m_socket;
    };
}


#endif //WEREWOLFSERVER_TCP_SESSION_HPP
