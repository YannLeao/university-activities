cmake_minimum_required(VERSION 3.20)
project(Activity3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(Activity3 main.cpp)

target_link_libraries(Activity3 ${CMAKE_THREAD_LIBS_INIT})