#ifndef MGE_PING_COMMAND_EXECUTOR_HPP
#define MGE_PING_COMMAND_EXECUTOR_HPP


#include <spdlog/spdlog.h>
#include "network/tcp_session_interface.hpp"
#include "ui/command_executor.hpp"

namespace mge {
    class ping_command_executor : public command_executor {
    public:
        ping_command_executor() = default;

        void execute() {
            spdlog::debug("Ping command called");
        }
    };
}

#endif // MGE_PING_COMMAND_EXECUTOR_HPP