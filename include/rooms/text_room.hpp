#ifndef MGE_TEXT_ROOM_HPP
#define MGE_TEXT_ROOM_HPP

#include "rooms/room_interface.hpp"

namespace mge {
    class text_room : public room_interface {
    public:
        explicit text_room(std::string const &name);
        void start() override;
    };
}// namespace mge


#endif//MGE_TEXT_ROOM_HPP
