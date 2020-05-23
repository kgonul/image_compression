cmake_minimum_required(VERSION 3.14)
project(data_compression_project)

set(CMAKE_CXX_STANDARD 14)
include_directories(libs/includes)
add_executable(data_compressor main.cpp huffman.cpp huffman.h util.cpp util.h image_manager.cpp image_manager.h)
find_library(png_lib png libs/lib)
target_link_libraries(data_compressor ${png_lib})

file(COPY images/fil.jpg DESTINATION "${CMAKE_BINARY_DIR}")