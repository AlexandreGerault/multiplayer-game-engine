#ifndef WEREWOLFSERVER_PACKET_HPP
#define WEREWOLFSERVER_PACKET_HPP

#include <array>
#include <vector>
#include <string>
#include <cstring>

namespace ww {
    using header_size_type = uint16_t;
    const int header_size = sizeof(header_size_type);

    class packet {
    public:
        packet() = delete;
        packet(std::string const& payload);
        std::vector<char> payload() const;

    private:
        header_size_type m_size;
        std::array<char, header_size> m_header;
        std::vector<char> m_body;
    };
}


#endif //WEREWOLFSERVER_PACKET_HPP
