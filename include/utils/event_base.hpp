#ifndef MGE_EVENT_BASE_HPP
#define MGE_EVENT_BASE_HPP

#include <spdlog/spdlog.h>

namespace mge {
    class event_base {
    public:
        virtual ~event_base() {
            spdlog::debug("Event destructued");
        }
    };
} // namespace mge

#endif// MGE_EVENT_BASE_HPP