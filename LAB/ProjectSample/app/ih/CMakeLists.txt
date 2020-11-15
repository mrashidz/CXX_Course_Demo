file(GLOB appih_src "src/*.cpp")
add_executable(ih main.cpp ${appih_src})
target_include_directories(ih PUBLIC  include
                                      ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/libcanio/include/
                                      ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/libuserio/include/)
target_link_libraries(ih canio x11keyio)