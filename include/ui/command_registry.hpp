#ifndef MGE_COMMAND_REGISTRY_HPP
#define MGE_COMMAND_REGISTRY_HPP

#include <unordered_map>

#include "ui/command.hpp"

namespace mge {
    class command_registry {
    public:
        command_registry() {}

        void registers(command& cmd);
        command& find(std::string const& name);
    private:
        std::unordered_map<std::string, command> m_commands;
    };
}


#endif //MGE_COMMAND_REGISTRY_HPP
