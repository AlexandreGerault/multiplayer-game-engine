#ifndef WEREWOLF_APPLICATION_HPP
#define WEREWOLF_APPLICATION_HPP

#include <boost/asio/io_context.hpp>
#include <string>
#include <spdlog/spdlog.h>
#include "core/configuration.hpp"
#include "network/tcp_server.hpp"
#include "rooms/server_rooms.hpp"

namespace ww {
	class application {
    public:
        application(boost::asio::io_context &io_context, boost::asio::ip::tcp::endpoint const& endpoint);
    private:
        configuration m_config;
        tcp_server m_server;
		server_rooms m_rooms;
	};
}

#endif //WEREWOLF_APPLICATION_HPP