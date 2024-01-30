cmake_minimum_required(VERSION 3.12)

project(SimpleTextCommunicator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB src
    "*.cpp"
    "*.c"
)
enable_testing()
add_subdirectory(app)

add_executable(${CMAKE_PROJECT_NAME} ${src})
target_link_libraries(${CMAKE_PROJECT_NAME} app)

add_test(NAME ${CMAKE_PROJECT_NAME} COMMAND ${CMAKE_PROJECT_NAME})