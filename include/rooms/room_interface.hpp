#ifndef WEREWOLF_ROOM_INTERFACE_HPP
#define WEREWOLF_ROOM_INTERFACE_HPP

#include <memory>
#include <set>
#include <string>
#include "core/configuration.hpp"
#include "network/tcp_session.hpp"

namespace ww {
    enum class room_state {
        lobby,
        in_progress
    };

    class room_interface {

    public:
        room_interface() = delete;
        explicit room_interface(const std::string &name);


        virtual void start() = 0;
        virtual std::string name() const { return m_name; }
        virtual void leave(std::shared_ptr<tcp_session> client);
        virtual void join(std::shared_ptr<tcp_session> client);

    protected:
        configuration m_config;
        room_state m_state;
        std::string m_name;
        std::set<std::shared_ptr<tcp_session>> m_clients;
    };
}// namespace ww

#endif// WEREWOLF_ROOM_INTERFACE_HPP
