cmake_minimum_required(VERSION 3.18)
project(Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")

# data structure sources

set(LINKED_LIST
        ../data_structures/linked_list/int_linked_list.c
        ../data_structures/linked_list/int_linked_list.h
        ../data_structures/linked_list/int_linked_list_test.cpp
        )

set(DYNAMIC_ARRAY
        ../data_structures/dynamic_array/dynamic_array.c
        ../data_structures/dynamic_array/dynamic_array.h
        ../data_structures/dynamic_array/dynamic_array_test.cpp)

set(HASH_TABLE
        ../data_structures/hash_table/hash_table.c
        ../data_structures/hash_table/hash_table.h
        ../data_structures/hash_table/hash_table_test.cpp)

set(BLOOM_FILTER
        ../data_structures/bloom_filter/bloom_filter.c
        ../data_structures/bloom_filter/bloom_filter.h
        ../data_structures/bloom_filter/bloom_filter_test.cpp)

# data structure test executables
add_executable(TEST_DYNAMIC_ARRAY
        main.cpp
        ${DYNAMIC_ARRAY}
        ${GTEST_LIBRARIES}
        )

add_executable(TEST_LINKED_LIST
        main.cpp
        ${LINKED_LIST}
        ${GTEST_LIBRARIES}
        )

add_executable(TEST_HASH_TABLE
        main.cpp
        ${HASH_TABLE}
        ${GTEST_LIBRARIES}
        )

add_executable(TEST_BLOOM_FILTER
        main.cpp
        ${BLOOM_FILTER}
        ${GTEST_LIBRARIES}
        )

add_executable(TEST_ALGORITHMS
        main.cpp
        ${LINKED_LIST}
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
target_link_libraries(TEST_HASH_TABLE ${GTEST_LIBRARIES})