
add_subdirectory(graphics)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../output")
add_executable(evis main.cpp)

target_link_libraries(evis PRIVATE graphics )