include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test test.cpp)
target_link_libraries(test gtest_main)

add_test(NAME QueueTests COMMAND test)