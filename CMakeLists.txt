cmake_minimum_required(VERSION 3.10)

# Project Name
project(FinalTermProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(StudentApp
    src/main.cpp
    src/model/student.cpp
    src/test/testLinkedList.cpp
)

# Set include directories
target_include_directories(StudentApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

