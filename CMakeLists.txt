cmake_minimum_required(VERSION 3.28.3)

project(evis)


set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "output")



if(WIN32)
set(SFML_LIB_DIR ${CMAKE_SOURCE_DIR}/external/SFML-Windows/lib)
    target_link_directories(evis PRIVATE ${SFML_LIB_DIR})
    target_link_libraries(evis 
        sfml-graphics 
        sfml-window 
        sfml-system 
        sfml-audio
    )
    add_custom_command(TARGET evis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${SFML_LIB_DIR}"
    $<TARGET_FILE_DIR:MySFMLApp>
)
endif()
if(UNIX)
    add_subdirectory(external/SFML)
endif()

add_subdirectory(src)









target_include_directories(evis PUBLIC external/SFML/include)
target_link_libraries(evis PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/assets DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/output)