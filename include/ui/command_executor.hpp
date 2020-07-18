#ifndef MGE_COMMAND_EXECUTOR_HPP
#define MGE_COMMAND_EXECUTOR_HPP

#include <spdlog/spdlog.h>

namespace mge {
    class command_executor {
    public:
        virtual void execute() = 0;

        virtual ~command_executor();
    };
}


#endif //MGE_COMMAND_EXECUTOR_HPP
