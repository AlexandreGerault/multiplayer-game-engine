#include <iostream>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include "core/application.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Werewolf server" << std::endl;

    boost::asio::io_context context;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 7777);

    ww::application app(context, endpoint);

    return 0;
}