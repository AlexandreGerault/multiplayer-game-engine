#include "network/tcp_listener_interface.hpp"

using namespace ww;

tcp_listener_interface::tcp_listener_interface(io_context &context, const endpoint &ep)
        : m_io_context{context},
          m_acceptor{context, ep} {}
