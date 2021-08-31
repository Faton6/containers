cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(lab_03)
set(CMAKE_CXX_STANDARD 14)


add_definitions( -lgtest_main)
include(FetchContent)

FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG release-1.8.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}  
"dycont_t.hpp"
"stack_t.hpp"
"list_t.hpp"
"queue_t.hpp"
"tree_t.hpp"
"main_lab3.cpp"
)

target_link_libraries(${PROJECT_NAME} gtest)

