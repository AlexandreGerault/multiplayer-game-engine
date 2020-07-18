#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <spdlog/spdlog.h>
#include "core/application.hpp"

int main(int argc, char *argv[]) {
    spdlog::set_level(spdlog::level::debug);

    spdlog::debug("Werewolf server");

    mge::application app;

    return EXIT_SUCCESS;
}