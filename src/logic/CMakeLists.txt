
add_library(logic ArrowGrid.cpp AssetManager.cpp)

target_link_libraries(logic PUBLIC graphics)
target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 