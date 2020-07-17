#include "core/application.hpp"
#include <string>

using namespace ww;

application::application() 
    : m_config{"general.config"}
    , m_registry {init_application_commands()}
    , m_command_observer{std::make_shared<command_observer>(m_registry)}
{
    spdlog::debug("Application created");

    int tcp_port{m_config.get<int>("tcp_port", 7777)};
    int ws_port{m_config.get<int>("ws_port", 8888)};

    boost::asio::io_context context;
    boost::asio::ip::tcp::endpoint tcp_endpoint(boost::asio::ip::tcp::v4(), tcp_port);
    boost::asio::ip::tcp::endpoint tcp_ws_endpoint(boost::asio::ip::tcp::v4(), ws_port);

    init_server_factory();

    try {
        create_listener("tcp_listener", context, tcp_endpoint, m_command_observer);
        create_listener("tcp_listener_websocket", context, tcp_ws_endpoint, m_command_observer);

        for (const auto &listener: m_listeners) {
            listener->run();
        }

        context.run();
    } catch (boost::system::system_error &ec) {
        spdlog::error("Cannot create listeners: {}", ec.what());
    }
}

void application::init_server_factory() {
    m_server_factory.registers(
            "tcp_listener",
            [](boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const &endpoint, std::weak_ptr<observer> obs)
                    -> std::unique_ptr<tcp_listener_interface> {
                return std::make_unique<tcp_listener>(context, endpoint, obs);
            });

    m_server_factory.registers(
            "tcp_listener_websocket",
            [](boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const &endpoint, std::weak_ptr<observer> obs)
                    -> std::unique_ptr<tcp_listener_interface> {
                return std::make_unique<tcp_listener_websocket>(context, endpoint, obs);
            });
}

command_registry application::init_application_commands() {
    command_registry _registry;
    command ping{
        "ping",
        "test latency",
        std::make_unique<mge::ping_command_executor>()
    };

    _registry.registers(ping);

    return _registry;
}