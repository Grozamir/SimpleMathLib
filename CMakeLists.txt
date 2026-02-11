cmake_minimum_required(VERSION 3.28.3)
project(SimpleMathLib)

set(CMAKE_CXX_STANDARD 20)

add_library(SimpleMathLib STATIC SimpleMath.cpp)

target_include_directories(SimpleMathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
