#include "ui/command_registry.hpp"

using namespace ww;

void command_registry::registers(command& cmd) {
    m_commands.insert({cmd.name(), std::move(cmd)});
}


command &command_registry::find(const std::string &name){
    auto iterator = m_commands.find(name);
    if (iterator == m_commands.end()) {
        throw std::range_error("Command not found");
    }
    auto&r = iterator->second;
    return r;
}
