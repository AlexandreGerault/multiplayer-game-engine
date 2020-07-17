#include "ui/command_executor.hpp"

command_executor::~command_executor() {
    spdlog::debug("Command executor destructed");
}