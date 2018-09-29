project(test_mutex)

set(CMAKE_CXX_FLAGS "-Wall -Werror -std=c++11 -pthread")

add_executable(
    test_mutex
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Main.cpp
)

