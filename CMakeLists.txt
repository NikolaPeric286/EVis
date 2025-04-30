cmake_minimum_required(VERSION 3.28.3)

project(evis)


set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "output")
add_subdirectory(src)

if (WIN32)
    message(STATUS "Configuring SFML from precompiled binary for Windows")
    set(SFML_DLL_DIR "${CMAKE_SOURCE_DIR}/external/SFML-Windows/SFML-2.6.2/bin")
    set(SFML_DLLS
        sfml-graphics-2.dll
        sfml-window-2.dll
        sfml-system-2.dll
        # Add more if needed: sfml-audio-2.dll, openal32.dll, freetype.dll
    )

    # Copy each DLL to the build output folder after build
    foreach(dll ${SFML_DLLS})
        add_custom_command(TARGET EVisApp POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${SFML_DLL_DIR}/${dll}"
                "$<TARGET_FILE_DIR:EVisApp>/${dll}"
        )
    endforeach()
    # Set SFML_DIR to point to binary CMake config
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-Windows/SFML-2.6.2/lib/cmake/SFML")

    find_package(SFML REQUIRED COMPONENTS graphics window system)

    target_include_directories(graphics PRIVATE "${SFML_INCLUDE_DIR}")
    target_link_libraries(graphics PRIVATE sfml-graphics sfml-window sfml-system)

elseif (UNIX)
    message(STATUS "Configuring SFML from source for Linux")

    # Build SFML from source
    add_subdirectory(external/SFML EXCLUDE_FROM_ALL)

    target_include_directories(graphics PRIVATE external/SFML/include)
    target_link_libraries(graphics PRIVATE sfml-graphics sfml-window sfml-system)
endif()





#add_dependencies(graphics sfml-graphics sfml-graphics sfml-window sfml-system sfml-audio)


target_include_directories(evis PUBLIC external/SFML/include)
target_link_libraries(evis PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

