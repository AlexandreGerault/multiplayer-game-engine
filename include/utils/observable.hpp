#ifndef WEREWOLF_OBSERVABLE_HPP
#define WEREWOLF_OBSERVABLE_HPP

#include <memory>
#include <vector>
#include <spdlog/spdlog.h>

#include "utils/observer.hpp"
#include "utils/event_base.hpp"

namespace ww  {
    class observable {
    public:
        void notify(std::shared_ptr<event_base> e);
        void add_observer(std::weak_ptr<observer> obs);

    private:
        std::vector<std::weak_ptr<observer>> m_observers;
    };
} // namespace ww


#endif // WEREWOLF_OBSERVABLE_HPP