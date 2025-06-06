cmake_minimum_required(VERSION 3.10)
project(MazeGenerator)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(maze_generator
    src/kruskal_maze.c
    src/disjoint_set.c
)
