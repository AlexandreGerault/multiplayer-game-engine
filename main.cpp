#include <iostream>
#include <boost/asio/io_context.hpp>
#include "core/application.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Werewolf server" << std::endl;

    boost::asio::io_context context;
    ww::application app(context);

    return 0;
}