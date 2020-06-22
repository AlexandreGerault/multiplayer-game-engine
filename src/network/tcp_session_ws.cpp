#include "network/tcp_session_ws.hpp"

using namespace ww;

tcp_session_ws::tcp_session_ws(boost::asio::ip::tcp::socket&& socket) : tcp_session_interface{}, m_websocket{std::move(socket)} {}
