#include "gtest/gtest.h"
extern "C" {
#include "dynamic_array.h"
}

TEST(make_dynamic_array, empty_arr) {
    dynamic_array* array = make_dynamic_array(0);
    ASSERT_TRUE(array != NULL);
    ASSERT_TRUE(array->data != NULL);
    free_dynamic_array(array);
}

TEST(make_dynamic_array, non_empty_arr) {
    int array_capacity = 8;
    dynamic_array* array = make_dynamic_array(array_capacity);
    ASSERT_TRUE(array != NULL);
    ASSERT_TRUE(array->data != NULL);
    free_dynamic_array(array);
}

TEST(push_back, preallocated_data) {
    int array_capacity = 8;
    dynamic_array* array = make_dynamic_array(array_capacity);
    for (int i = 0; i < array_capacity; ++i) {
        push_back(array, i);
    }
    ASSERT_TRUE(array->data != NULL);
    free_dynamic_array(array);
}

TEST(push_back, resizing) {
    int array_capacity = 8;
    dynamic_array* array = make_dynamic_array(1);
    for (int i = 0; i < array_capacity; ++i) {
        push_back(array, i);
    }
    ASSERT_TRUE(array->data != NULL);
    free_dynamic_array(array);
}

TEST(pop_back, empty_array) {
    int array_capacity = 0;
    dynamic_array* array = make_dynamic_array(array_capacity);
    ASSERT_TRUE(pop_back(array) == EMPTY_ARRAY_POP);
    free_dynamic_array(array);
}

TEST(pop_back, non_empty_array) {
    int array_capacity = 8;
    dynamic_array* array = make_dynamic_array(array_capacity);
    for (int i = 0; i < array_capacity; ++i) {
        push_back(array, i);
    }
    for (int i = 0; i < array_capacity; ++i) {
        pop_back(array);
    }
    ASSERT_EQ(array->size, 0);
    free_dynamic_array(array);
}