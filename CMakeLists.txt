cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CXX_FLAGS "-std=c++0x")
add_subdirectory(src)
add_subdirectory(algorithms)
