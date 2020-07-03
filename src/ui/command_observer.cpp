#include "ui/command_observer.hpp"

using namespace ww;

void command_observer::notify(std::shared_ptr<event_base> e) {
    std::shared_ptr<data_received_event> data_received = std::dynamic_pointer_cast<data_received_event>(e);

    if (data_received) {
        spdlog::debug("DATA_RECEIVED_EVENT handled by command observer");
    } else {
        spdlog::debug("EVENT skipped by command observer");
    }
}