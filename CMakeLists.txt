cmake_minimum_required(VERSION 3.28.3)

project(evis)


set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "output")
include_directories(${CMAKE_SOURCE_DIR}/external/SFML-Windows/SFML-2.6.2/include)

add_subdirectory(src)

if(UNIX)
    message("Compiling SFML from source on Linux")
    add_subdirectory(external/SFML)
    target_link_libraries(evis PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)
endif()











target_include_directories(evis PUBLIC external/SFML/include)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/assets DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/output)