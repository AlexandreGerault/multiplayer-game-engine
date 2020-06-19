cmake_minimum_required(VERSION 3.16.5)

project(WerewolfServer VERSION 0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (WIN32)
    message(STATUS "Windows Platform")
    find_package(Boost 1.73.0 COMPONENTS thread system REQUIRED PATHS libs/boost_1_73_0_windows)
endif(WIN32)
if (UNIX)
    message(STATUS "Unix Platform")
    find_package(Boost 1.73.0 COMPONENTS thread system REQUIRED PATHS libs/boost_1_73_0_arch_linux)
endif(UNIX)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    set(SERVER_SOURCE_FILES
            include/utils/factory.hpp
            src/core/configuration.cpp
            src/rooms/room_interface.cpp
            src/rooms/text_room.cpp
            src/rooms/voice_room.cpp
            src/rooms/server_rooms.cpp
            src/network/tcp_server.cpp
            src/network/tcp_connection.cpp
            src/core/application.cpp src/network/packet.cpp
            )

    add_library(server_lib ${SERVER_SOURCE_FILES})
    target_include_directories(server_lib PUBLIC include)
    add_executable(server main.cpp)
    target_link_libraries(server ${Boost_LIBRARIES})
    target_link_directories(server PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(server server_lib)
endif()

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
