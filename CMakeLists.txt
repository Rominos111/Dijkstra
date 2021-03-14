cmake_minimum_required(VERSION 3.10)
project(Graphs_Dijkstra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

include_directories(./src)
include_directories(./include)

set(SOURCE_FILES
        main.cpp
        src/Node.tpp
        src/Link.tpp
        src/PriorityQueue.tpp
)

set(HEADER_FILES
        include/Node.hpp
        include/Link.hpp
        include/PriorityQueue.hpp
)

add_executable(Graphs_Dijkstra ${SOURCE_FILES} ${HEADER_FILES})
