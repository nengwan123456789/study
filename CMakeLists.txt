cmake_minimum_required(VERSION 3.0)
project(demo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(. src)
message("src ${src}")
add_executable(test ${src})