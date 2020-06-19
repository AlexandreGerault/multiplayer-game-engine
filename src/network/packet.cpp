#include "network/packet.hpp"

using namespace ww;

packet::packet(std::string const& payload) : m_size{static_cast<header_size_type>(payload.length())} {
    auto cursor = reinterpret_cast<char *>(&m_size);
    std::strcpy(m_header.data(), cursor);

    m_body.reserve(m_size);
    std::copy(payload.begin(), payload.end(), std::back_inserter(m_body));
}


std::vector<char> packet::payload() const {
    std::vector<char> payload;
    payload.reserve(m_size + sizeof(m_size));

    std::copy(m_header.begin(), m_header.end(), std::back_inserter(payload));
    std::copy(m_body.begin(), m_body.end(), std::back_inserter(payload));

    return payload;
}