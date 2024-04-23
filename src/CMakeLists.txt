#=======================================================================================================================
# Preamble
#=======================================================================================================================
cmake_minimum_required(VERSION 3.10)
project(FinalTermProject.src)
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#=======================================================================================================================
# Include boost::nowide library (required for Demo4)
#=======================================================================================================================
add_subdirectory(problem-1/external/nowide EXCLUDE_FROM_ALL)

#=======================================================================================================================
# Define Demo1 target
#=======================================================================================================================
add_executable(
            Problem1 problem-1/main.cpp 
            problem-1/model/student.cpp 
            problem-1/model/data.cpp 
            problem-1/model/output.cpp
            )
add_executable(Problem2.1 problem-2.1/main.cpp)
target_link_libraries(Problem1 PRIVATE OpenXLSX::OpenXLSX nowide::nowide)
target_link_libraries(Problem2.1)
