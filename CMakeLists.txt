cmake_minimum_required(VERSION 4.1)
project(SimpleMathLib)

set(CMAKE_CXX_STANDARD 20)

add_library(SimpleMathLib STATIC SimpleMath.cpp)
