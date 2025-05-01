
add_library(graphics ArrowShape.cpp DraggableObject.cpp SideBar.cpp Sensor.cpp Button.cpp)


target_include_directories(graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 