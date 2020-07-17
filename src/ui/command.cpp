#include "ui/command.hpp"

using namespace ww;

std::string command::name() const {
    return m_name;
}

command::command(std::string name, std::string description, std::unique_ptr<command_executor> executor)
        : m_name{name}, m_description{description}, m_executor{std::move(executor)} {

}

void command::run() {
    m_executor->execute();
}
