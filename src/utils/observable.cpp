#include "utils/observable.hpp"

using namespace ww;

void observable::notify(std::shared_ptr<event_base> e) {
    for (auto &observer : m_observers) {
        if (auto obs = observer.lock()) {
            obs->notify(e);
        }
    }
}

void observable::add_observer(std::weak_ptr<observer> obs) {
    spdlog::debug("Registering an observer");
    m_observers.push_back(obs);
}