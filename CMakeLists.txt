cmake_minimum_required(VERSION 3.15)
project(wsl_localhost_addr_server)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(FetchContent)
# cpp-httplib
FetchContent_Declare(httplib GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git GIT_TAG v0.14.3)
FetchContent_MakeAvailable(httplib)
# openssl
FetchContent_Declare(openssl GIT_REPOSITORY https://github.comm/openssl/openssl.git GIT_TAG "openssl-3.2.0")
FetchContent_MakeAvailable(openssl)

add_executable(wsl_localhost_addr_server main.cpp)
target_link_libraries(wsl_localhost_addr_server PRIVATE httplib::httplib OpenSSL::SSL OpenSSL::Crypto)

# install(TARGETS wsl_localhost_addr_server DESTINATION ${CMAKE_INSTALL_PREFIX})