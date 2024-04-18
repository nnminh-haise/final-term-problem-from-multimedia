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
    src/Knight/Knight.cpp
)

add_executable(Task2.1 src/2.1/main.cpp)

# Set include directories
target_include_directories(StudentApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Task2.1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

