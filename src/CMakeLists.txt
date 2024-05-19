# =======================================================================================================================
# Preamble
# =======================================================================================================================
cmake_minimum_required(VERSION 3.10)
project(FinalTermProject.src)

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# =======================================================================================================================
# =======================================================================================================================
# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME OFF)
# set(Boost_NO_SYSTEM_PATHS TRUE)

# if(Boost_NO_SYSTEM_PATHS)
# set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/problem-1/external/boost_1_85_0")
# set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/boost")
# set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/libs")
# set(Boost_DIR "${BOOST_INCLUDE_DIRS}")
# endif(Boost_NO_SYSTEM_PATHS)

# find_package(Boost 1.85.0 COMPONENTS nowide)

# add_subdirectory(problem-1/external/boost_1_85_0/libs/nowide EXCLUDE_FROM_ALL)
add_subdirectory(problem-1/external/nowide EXCLUDE_FROM_ALL)

# =======================================================================================================================
# =======================================================================================================================
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
