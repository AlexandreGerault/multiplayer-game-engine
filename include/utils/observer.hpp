#ifndef WEREWOLF_OBSERVER_HPP
#define WEREWOLF_OBSERVER_HPP

#include <memory>
#include "utils/event_base.hpp"

namespace ww {
    class observer {
    public:
        virtual void notify(std::shared_ptr<event_base>) = 0;
    };
} // namespace ww

#endif // WEREWOLF_OBSERVER_HPP