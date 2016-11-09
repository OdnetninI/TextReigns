cmake_minimum_required(VERSION 2.8)
project(TextReigns)

set(CMAKE_CXX_FLAGS "-std=c++14 -Werror -Wall -Ofast -I${CMAKE_SOURCE_DIR}/src")

# This is a built-in utility to grab all the source files from a specific
# location into a list
#AUX_SOURCE_DIRECTORY(./src LOG_SOURCES)
FILE(GLOB_RECURSE LOG_SOURCES  src/*.cpp)

# Define sources and executable
set(EXECUTABLE_NAME "TextReigns")
add_executable(${EXECUTABLE_NAME} ${LOG_SOURCES})


# Detect and add SFML
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
#find_package(SFML 2 REQUIRED system window graphics network audio)
#if(SFML_FOUND)
#  include_directories(${SFML_INCLUDE_DIR})
#  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
#endif()

#find_package(OpenMP)
#if (OPENMP_FOUND)
#    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION .)

#file(COPY ./Data DESTINATION .)
