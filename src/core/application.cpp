#include "core/application.hpp"
#include <string>

using namespace ww;

application::application(boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const& endpoint) 
    : m_config("general.config"), m_server(
        context,
        endpoint
    ) {

    spdlog::debug("Application created");
    try {
        m_server.run();
    } catch (boost::system::system_error &ec) {
        spdlog::error("Cannot create application: {}", ec.what());
    }
}