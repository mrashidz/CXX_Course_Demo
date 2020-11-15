#considered bad practice
file(GLOB libx11keyio_src "src/keyboard_reader/x11/*.cpp")
add_library(x11keyio STATIC ${libx11keyio_src})
set_target_properties(x11keyio PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libx11keyio.a"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include"
)
target_link_libraries(x11keyio PUBLIC X11)
target_include_directories(x11keyio PUBLIC include/userio/keyboard_reader/x11)