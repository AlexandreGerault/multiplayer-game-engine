#ifndef WEREWOLF_VOICE_ROOM_HPP
#define WEREWOLF_VOICE_ROOM_HPP

#include "rooms/room_interface.hpp"

namespace ww {
    class voice_room : public room_interface {
    public:
        explicit voice_room(const std::string& name);
        void start() override;
    };
}// namespace ww


#endif//WEREWOLF_VOICE_ROOM_HPP
