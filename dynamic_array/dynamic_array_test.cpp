#include "gtest/gtest.h"
extern "C" {
#include "dynamic_array.h"
}

TEST(make_dynamic_array, empty_arr) {
    dynamic_array* array = make_dynamic_array(0);
    ASSERT_TRUE(array != NULL);
    ASSERT_TRUE(array->data != NULL) << [array]()->std::string {
        free(array);
        return "Error allocating data for dynamic_array";
    }();
    free_dynamic_array(array);
}

TEST(make_dynamic_array, non_empty_arr) {
    dynamic_array* array = make_dynamic_array(10);
    ASSERT_TRUE(array != NULL);
    // if assert fails free memory allocated for dynamic_array struct
    ASSERT_TRUE(array->data != NULL) << [array]()->std::string {
                    free(array);
                    return "Error allocating data for dynamic_array";
                }();
    free_dynamic_array(array);
}

TEST(push_back, preallocated_data) {
    int array_capacity = 8;
    dynamic_array* array = make_dynamic_array(array_capacity);
    for (int i = 0; i < array_capacity; ++i) {
        push_back(array, i);
    }
    ASSERT_TRUE(array->data != NULL) << [array]()->std::string {
                    free(array);
                    return "Error allocating data for dynamic_array";
                }();
    free_dynamic_array(array);
}