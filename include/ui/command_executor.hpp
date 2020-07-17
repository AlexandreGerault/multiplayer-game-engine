#ifndef WEREWOLFSERVER_COMMAND_EXECUTOR_HPP
#define WEREWOLFSERVER_COMMAND_EXECUTOR_HPP

#include <spdlog/spdlog.h>

class command_executor {
    public:
        virtual void execute() = 0;
        virtual ~command_executor();
};


#endif //WEREWOLFSERVER_COMMAND_EXECUTOR_HPP
