cmake_minimum_required(VERSION 3.6)
project(diamond_kata)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_subdirectory(diamond)

set(SOURCE_FILES main.cpp)
add_executable(diamond_kata ${SOURCE_FILES})

target_link_libraries(diamond_kata LINK_PUBLIC diamond)