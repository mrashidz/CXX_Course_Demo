#bad practice
file(GLOB ee_src "src/*.cpp")
add_executable(ee main.cpp ${ee_src})
target_include_directories(ee PUBLIC  include
                                      ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/libcanio/include/)
target_link_libraries(ee canio) 
