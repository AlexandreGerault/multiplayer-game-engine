project(server_google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_server_run ConfigurationTests.cpp)

target_link_libraries(Google_Tests_server_run server_lib)

target_link_libraries(Google_Tests_server_run gtest gtest_main)