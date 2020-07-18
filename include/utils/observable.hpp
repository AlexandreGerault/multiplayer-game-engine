#ifndef MGE_OBSERVABLE_HPP
#define MGE_OBSERVABLE_HPP

#include <memory>
#include <vector>
#include <spdlog/spdlog.h>

#include "utils/observer.hpp"
#include "utils/event_base.hpp"

namespace mge  {
    class observable {
    public:
        void notify(std::shared_ptr<event_base> e);
        void add_observer(std::weak_ptr<observer> obs);

    private:
        std::vector<std::weak_ptr<observer>> m_observers;
    };
} // namespace mge


#endif // MGE_OBSERVABLE_HPP