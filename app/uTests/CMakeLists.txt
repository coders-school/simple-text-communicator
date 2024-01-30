cmake_minimum_required(VERSION 3.5)

add_subdirectory(dependency)

file(GLOB_RECURSE unit_test_src
    "*.cpp"
)

add_executable(${CMAKE_PROJECT_NAME}_gTests ${unit_test_src})
target_link_libraries(${CMAKE_PROJECT_NAME}_gTests PRIVATE gtest gtest_main app)
target_compile_options(${PROJECT_NAME}_gTests PUBLIC --coverage)
target_link_options(${PROJECT_NAME}_gTests PUBLIC --coverage)
add_test(NAME ${CMAKE_PROJECT_NAME}_gTests COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}_gTests)
add_test(NAME "${CMAKE_PROJECT_NAME}_gTests_valgrind"
    COMMAND valgrind --leak-check=full
    --show-leak-kinds=all
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}_gTests
)