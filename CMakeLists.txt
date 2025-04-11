# DO NOT MODIFY

cmake_minimum_required(VERSION 3.13)
project(EECS348-Lab-7)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

# Add the main executable target
add_executable(matrix_ops main.cpp)
# Ensure matrix.hpp (in the current source directory ".") can be found
target_include_directories(matrix_ops PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)
