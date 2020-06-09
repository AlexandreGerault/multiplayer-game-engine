#include "core/application.hpp"
#include <iostream>

using namespace ww;

application::application(boost::asio::io_context &context) 
    : m_server(
        context,
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 7777)
    ) {
    std::cout << "Création de l'application" << std::endl;
    m_rooms.create_room("text_room", "My first text room");
}