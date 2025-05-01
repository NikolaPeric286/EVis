
add_subdirectory(graphics)
add_subdirectory(logic)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../output")
add_executable(evis main.cpp)

target_link_libraries(evis PRIVATE graphics logic)


if(WIN32)
    message("Compiling with SFML binaries on Windows")
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/SFML-Windows/SFML-2.6.2")
    set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
    set(SFML_LIB_DIR "${SFML_ROOT}/lib")
    set(SFML_DLL_DIR "${SFML_ROOT}/bin")

    target_include_directories(evis PRIVATE ${SFML_INCLUDE_DIR})

    # If you're linking statically, define this:
    target_compile_definitions(evis PRIVATE SFML_STATIC)

    # Link directly to static libraries (.a files)
    target_link_libraries(evis PRIVATE
        ${SFML_LIB_DIR}/libsfml-graphics.a
        ${SFML_LIB_DIR}/libsfml-window.a
        ${SFML_LIB_DIR}/libsfml-system.a
        ${SFML_LIB_DIR}/libsfml-audio.a
    )

    target_link_libraries(evis PRIVATE
    -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32
    -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32
    )

    file(GLOB SFML_DLLS "${SFML_DLL_DIR}/*.dll")
    add_custom_command(TARGET evis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SFML_DLLS}
    $<TARGET_FILE_DIR:evis>
)
endif()

