cmake_minimum_required(VERSION 3.13)
project(ranges2020)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} min_dist)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
