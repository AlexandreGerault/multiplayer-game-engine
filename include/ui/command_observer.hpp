#ifndef WEREWOLF_COMMAND_OBSERVER_HPP
#define WEREWOLF_COMMAND_OBSERVER_HPP

#include <memory>
#include <spdlog/spdlog.h>

#include "utils/observer.hpp"
#include "utils/event_base.hpp"
#include "network/data_received_event.hpp"
#include "ui/command_registry.hpp"

namespace ww {
    class command_observer : public observer {
    public:
        command_observer(command_registry  &registry) : m_registry{registry} {
            spdlog::debug("Command observer created!");
        }

        void notify(std::shared_ptr<event_base> e);

    private:
        command_registry & m_registry;
    };
}

#endif // WEREWOLF_COMMAND_OBSERVER_HPP