#include "core/application.hpp"
#include <string>

using namespace ww;

application::application(boost::asio::io_context &context, boost::asio::ip::tcp::endpoint const& endpoint) 
    : m_config("general.config"), m_server(
        context,
        endpoint
    ) {
    std::cout << "Création de l'application" << std::endl;
    try {
        m_server.run();
    } catch (boost::system::system_error &ec) {
        std::cout << "Error: " << ec.what() << "\n";
    }
}