cmake_minimum_required(VERSION 3.16)
project(lab_5 C)

set(CMAKE_C_STANDARD 99)

include_directories(graph)
include_directories(controller)
include_directories(view)

add_executable(lab_5 main.c graph/Graph.c graph/Queue.c controller/GraphController.c view/Dialog.c)
add_executable(test test.c graph/Graph.c graph/Queue.c)

target_link_libraries(lab_5 m)
target_link_libraries(test m)
