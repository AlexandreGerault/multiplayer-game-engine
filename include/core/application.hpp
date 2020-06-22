#ifndef WEREWOLF_APPLICATION_HPP
#define WEREWOLF_APPLICATION_HPP

#include <boost/asio/io_context.hpp>
#include <string>
#include <spdlog/spdlog.h>

#include "core/configuration.hpp"
#include "network/tcp_listener_interface.hpp"
#include "network/tcp_listener.hpp"
#include "network/tcp_listener_ws.hpp"
#include "rooms/server_rooms.hpp"
#include "utils/factory.hpp"

namespace ww {
    class application {
    public:
        application();

        template<class... Args>
        void create_server(std::string const &type, Args &&... args) {
            auto server = m_server_factory.make(type, args...);
            m_servers.insert(std::move(server));
        }


    private:
        void init_server_factory();

        configuration m_config;
        factory<tcp_listener_interface, boost::asio::io_context&, boost::asio::ip::tcp::endpoint const&> m_server_factory;
        std::unordered_set<std::unique_ptr<tcp_listener_interface>> m_servers;
        server_rooms m_rooms;
    };
}

#endif //WEREWOLF_APPLICATION_HPP