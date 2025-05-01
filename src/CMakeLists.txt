
add_subdirectory(graphics)
add_subdirectory(logic)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../output")
add_executable(evis main.cpp)

target_link_libraries(evis PRIVATE graphics logic)