cmake_minimum_required(VERSION 3.17)

project(WerewolfServer VERSION 0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SERVER_SOURCE_FILES
        include/utils/factory.hpp
        src/core/configuration.cpp
        src/rooms/room_interface.cpp
        src/rooms/text_room.cpp
        src/rooms/voice_room.cpp
        src/rooms/server_rooms.cpp
        src/network/tcp_server.cpp
        src/network/tcp_connection.cpp
        )
add_library(server_lib ${SERVER_SOURCE_FILES})
target_include_directories(server_lib PUBLIC include)
add_executable(server main.cpp)
target_link_libraries(server server_lib)