#ifndef WEREWOLF_TEXT_ROOM_HPP
#define WEREWOLF_TEXT_ROOM_HPP

#include <rooms/room_interface.hpp>

namespace ww {
    class text_room : public room_interface {
    public:
        explicit text_room(std::string const &name);
        void start() override;
    };
}// namespace ww


#endif//WEREWOLF_TEXT_ROOM_HPP
