#include "ui/command_executor.hpp"

using namespace mge;

command_executor::~command_executor() {
    spdlog::debug("Command executor destructed");
}