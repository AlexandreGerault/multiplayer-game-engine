#ifndef WEREWOLF_EVENT_BASE_HPP
#define WEREWOLF_EVENT_BASE_HPP

#include <spdlog/spdlog.h>

namespace ww {
    class event_base {
    public:
        virtual ~event_base() {
            spdlog::debug("Event destructued");
        }
    };
} // namespace ww

#endif// WEREWOLF_EVENT_BASE_HPP