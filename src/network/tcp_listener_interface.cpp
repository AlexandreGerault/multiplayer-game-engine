#include "network/tcp_listener_interface.hpp"

using namespace ww;

tcp_listener_interface::tcp_listener_interface(boost::asio::io_context &context,
                                               boost::asio::ip::tcp::endpoint const &ep)
        : m_io_context{context},
          m_acceptor{context, ep} {}
