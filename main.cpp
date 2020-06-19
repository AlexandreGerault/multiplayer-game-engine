#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <spdlog/spdlog.h>
#include "core/application.hpp"

int main(int argc, char *argv[]) {
    spdlog::set_level(spdlog::level::debug);

    spdlog::debug("Werewolf server");

    int port{};

    if (argc > 1) {
        port = std::atoi(argv[1]);
    } else {
        port = 7777;
    }

    try {
        spdlog::info("Port: {}", port);
        boost::asio::io_context context;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);

        ww::application app(context, endpoint);
    } catch (boost::system::system_error &ec) {
        spdlog::error("Cannot create io_context: {}", ec.what());
    }

    return EXIT_SUCCESS;
}