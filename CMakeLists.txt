cmake_minimum_required(VERSION 3.13)
project(WerewolfServer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.73.0 REQUIRED)
find_package(spdlog 1.6.1 REQUIRED)

set(SERVER_SOURCE_FILES
    src/core/configuration.cpp
    src/rooms/room_interface.cpp
    src/rooms/text_room.cpp
    src/rooms/voice_room.cpp
    src/rooms/server_rooms.cpp
    src/network/tcp_listener.cpp
    src/network/tcp_session.cpp
    src/core/application.cpp
    src/network/packet.cpp
    src/network/tcp_listener_interface.cpp
    src/network/tcp_session_interface.cpp
    src/network/tcp_session_websocket.cpp
    src/network/tcp_listener_websocket.cpp
    src/utils/observable.cpp
    src/network/data_received_event.cpp
    src/ui/command_observer.cpp
    src/ui/command_registry.cpp
    src/ui/command_interface.cpp
    src/ui/command_executor.cpp
    )

add_library(server_lib ${SERVER_SOURCE_FILES})
target_include_directories(server_lib
        PUBLIC include
        PUBLIC ${Boost_INCLUDE_DIRS}
        )
target_link_libraries(server_lib
                      PUBLIC ${Boost_LIBRARIES}
                      PRIVATE spdlog::spdlog)
target_compile_definitions(server_lib
                           PUBLIC
                           BOOST_BIND_GLOBAL_PLACEHOLDERS
                           $<$<PLATFORM_ID:Windows>:_WIN32_WINNT=0x0A00>)

add_executable(server main.cpp)
target_link_libraries(server PRIVATE server_lib)
