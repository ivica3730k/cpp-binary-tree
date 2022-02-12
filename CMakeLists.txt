cmake_minimum_required(VERSION 3.20)
project(cpp_binary_tree)

set(CMAKE_CXX_STANDARD 17)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(test tree.h test.cpp)
target_link_libraries(test ${Boost_LIBRARIES})
