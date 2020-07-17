#include "ui/command_observer.hpp"

using namespace ww;

void command_observer::notify(std::shared_ptr<event_base> e) {
    std::shared_ptr<data_received_event> data_received = std::dynamic_pointer_cast<data_received_event>(e);

    if (data_received) {
        spdlog::debug("DATA_RECEIVED_EVENT handled by command observer");

        std::string msg{data_received->content()};
        std::string delimiter{" "};
        std::string command_name{msg.substr(0, msg.find(delimiter))};

        try {
            command &cmd = m_registry.find(command_name);
            cmd.run();
        } catch (std::range_error& e) {
            spdlog::error(e.what());
        }

    } else {
        spdlog::debug("EVENT skipped by command observer");
    }
}