cmake_minimum_required(VERSION 3.10)
project(FinalTermProject.src)

add_subdirectory(problem-1/external/nowide EXCLUDE_FROM_ALL)

add_executable(
    Problem1 problem-1/main.cpp
    problem-1/model/student.cpp
    problem-1/model/data.cpp
    problem-1/model/output.cpp
)
add_executable(Problem2.1 problem-2.1/main.cpp)
add_executable(Knight Knight/Knight.cpp)
target_link_libraries(Problem1 PRIVATE OpenXLSX::OpenXLSX nowide::nowide)
target_link_libraries(Problem2.1)
