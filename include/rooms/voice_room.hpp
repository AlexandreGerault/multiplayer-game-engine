#ifndef MGE_VOICE_ROOM_HPP
#define MGE_VOICE_ROOM_HPP

#include "rooms/room_interface.hpp"

namespace mge {
    class voice_room : public room_interface {
    public:
        explicit voice_room(const std::string& name);
        void start() override;
    };
}// namespace mge


#endif//MGE_VOICE_ROOM_HPP
