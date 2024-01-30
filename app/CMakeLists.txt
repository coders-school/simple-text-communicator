cmake_minimum_required(VERSION 3.5)

file(GLOB_RECURSE app_src
    "*.cpp"
    "*.c"
)

list(FILTER app_src EXCLUDE REGEX "uTests/.*$")

add_library(app "${app_src}")

add_subdirectory(uTests)