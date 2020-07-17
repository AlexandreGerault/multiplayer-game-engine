#include "network/data_received_event.hpp"
#include "network/tcp_session_interface.hpp"

using namespace ww;

data_received_event::data_received_event(std::shared_ptr<tcp_session_interface> session_ptr, std::string data)
    : event_base {}, m_session_ptr{session_ptr}, m_data{data} {
    spdlog::debug("Data received event constructed");
}

std::string data_received_event::content() const {
    return m_data;
}
