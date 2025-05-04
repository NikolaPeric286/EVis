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
    message("Platform: Linux")
    find_package(SFML 2.5 COMPONENTS graphics window system audio)

    if(SFML_FOUND)
        message("SFML Found")
    else()
        message("SFML Not found, Compiling SFML from source on Linux")
        
        set(SFML_BUILD_NETWORK FALSE)
        set(SFML_BUILD_AUDIO FALSE)
        add_subdirectory(external/SFML)
        
    endif()
    
    target_link_libraries(evis PUBLIC sfml-graphics sfml-window sfml-system)
endif()











target_include_directories(evis PUBLIC external/SFML/include)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/assets DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/output)