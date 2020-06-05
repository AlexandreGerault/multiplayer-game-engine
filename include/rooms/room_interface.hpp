#ifndef WEREWOLF_ROOM_INTERFACE_HPP
#define WEREWOLF_ROOM_INTERFACE_HPP

#include <core/configuration.hpp>
#include <string>

namespace ww {
    enum class room_state {
        lobby,
        in_progress
    };

    class room_interface {

    public:
        /**
         * It is necessary to initialize name
         */
        room_interface() = delete;

        explicit room_interface(const std::string &name);


        virtual void start() = 0;

        virtual std::string name() const { return m_name; }

    protected:
        configuration m_config;
        room_state m_state;
        std::string m_name;
    };
}// namespace ww

#endif// WEREWOLF_ROOM_INTERFACE_HPP
