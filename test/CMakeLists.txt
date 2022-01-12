cmake_minimum_required(VERSION 3.18)
project(Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")

set(INT_LINKED_LIST
        ../linked_list/int_linked_list.c
        ../linked_list/int_linked_list.h
        ../linked_list/int_linked_list_test.cpp
        )

set(DYNAMIC_ARRAY
        ../dynamic_array/dynamic_array.c
        ../dynamic_array/dynamic_array.h
        ../dynamic_array/dynamic_array_test.cpp)

add_executable(TEST_DYNAMIC_ARRAY
        main.cpp
        ${DYNAMIC_ARRAY}
        ${GTEST_LIBRARIES}
        )

add_executable(TEST_LINKED_LIST
        main.cpp
        ${INT_LINKED_LIST}
        ${GTEST_LIBRARIES}
        )

add_executable(TEST_ALGORITHMS
        main.cpp
        ${INT_LINKED_LIST}
        ${DYNAMIC_ARRAY}
        ${GTEST_LIBRARIES}
        )

enable_testing()
find_package(GTest REQUIRED)
include_directories(&{GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})
target_link_libraries(TEST_ALGORITHMS ${GTEST_LIBRARIES})
target_link_libraries(TEST_DYNAMIC_ARRAY ${GTEST_LIBRARIES})
target_link_libraries(TEST_LINKED_LIST ${GTEST_LIBRARIES})