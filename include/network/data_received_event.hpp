#ifndef MGE_DATA_RECEIVED_EVENT_HPP
#define MGE_DATA_RECEIVED_EVENT_HPP

#include <memory>
#include <spdlog/spdlog.h>
#include "utils/event_base.hpp"

namespace mge {
    class tcp_session_interface;

    class data_received_event : public event_base {
    public:
        data_received_event() = delete;
        data_received_event(std::shared_ptr<tcp_session_interface> session_ptr, std::string data);
        std::string content() const;

    private:
        std::shared_ptr<tcp_session_interface> m_session_ptr;
        std::string m_data;
    };
}

#endif // MGE_DATA_RECEIVED_EVENT_HPP