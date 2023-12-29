cmake_minimum_required(VERSION 3.15)
project(wsl_localhost_addr_server)

include(FetchContent)
# cpp-httplib
FetchContent_Declare(httplib GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git GIT_TAG v0.14.3)
FetchContent_MakeAvailable(httplib)

add_executable(wsl_localhost_addr_server main.cpp)
target_link_libraries(wsl_localhost_addr_server PRIVATE httplib::httplib)