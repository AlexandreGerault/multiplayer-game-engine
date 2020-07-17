#ifndef WEREWOLFSERVER_COMMAND_REGISTRY_HPP
#define WEREWOLFSERVER_COMMAND_REGISTRY_HPP

#include <unordered_map>

#include "ui/command.hpp"

namespace ww {
    class command_registry {
    public:
        command_registry() {}

        void registers(command& cmd);
        command& find(std::string const& name);
    private:
        std::unordered_map<std::string, command> m_commands;
    };
}


#endif //WEREWOLFSERVER_COMMAND_REGISTRY_HPP
