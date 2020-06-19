#include <iostream>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include "core/application.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Werewolf server" << std::endl;

    int port{};

    if (argc > 1) {
        port = std::atoi(argv[1]);
    } else {
        port = 7777;
    }

    try {
        std::cout << "Port: " << port << std::endl;
        boost::asio::io_context context;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);

        ww::application app(context, endpoint);
    } catch (boost::system::system_error &ec) {
        std::cout << "Cannot create io_context. Error: " << ec.what() << std::endl;
    }

    return EXIT_SUCCESS;
}