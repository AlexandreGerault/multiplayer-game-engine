#ifndef MGE_OBSERVER_HPP
#define MGE_OBSERVER_HPP

#include <memory>
#include "utils/event_base.hpp"

namespace mge {
    class observer {
    public:
        virtual void notify(std::shared_ptr<event_base>) = 0;
    };
} // namespace mge

#endif // MGE_OBSERVER_HPP