#ifndef WEREWOLF_APPLICATION_HPP
#define WEREWOLF_APPLICATION_HPP

#include <boost/asio/io_context.hpp>
#include <string>
#include <spdlog/spdlog.h>

#include "core/configuration.hpp"
#include "network/tcp_listener_interface.hpp"
#include "network/tcp_listener.hpp"
#include "network/tcp_listener_websocket.hpp"
#include "rooms/server_rooms.hpp"
#include "utils/factory.hpp"

namespace ww {
    class application {
    public:
        application();

        template<class... Args>
        void create_listener(std::string const &type, Args &&... args) {
            auto server = m_server_factory.make(type, args...);
            m_listeners.insert(std::move(server));
        }

    private:
        void init_server_factory();

        factory<tcp_listener_interface, boost::asio::io_context&, boost::asio::ip::tcp::endpoint const&> m_server_factory;
        std::unordered_set<std::unique_ptr<tcp_listener_interface>> m_listeners;
        configuration m_config;
        server_rooms m_rooms;
    };
}

#endif //WEREWOLF_APPLICATION_HPP