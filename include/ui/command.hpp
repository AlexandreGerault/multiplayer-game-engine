#ifndef MGE_COMMAND_INTERFACE_HPP
#define MGE_COMMAND_INTERFACE_HPP

#include<memory>
#include <string>
#include "ui/command_executor.hpp"

namespace mge {
    class command {
    public:
        command() = delete;
        command(std::string name, std::string description, std::unique_ptr<command_executor> executor);
        std::string name() const;
        void run();

    private:
        std::string m_name;
        std::string m_description;
        std::unique_ptr<command_executor> m_executor;
    };
}


#endif //MGE_COMMAND_INTERFACE_HPP
