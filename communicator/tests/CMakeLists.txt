cmake_minimum_required(VERSION 3.5)
project(CommunicatorGTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example-gt exampleTest.cpp)
target_link_libraries(example-gt gtest_main)
enable_testing()
add_test(NAME example_test COMMAND example-gt)