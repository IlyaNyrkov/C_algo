#include "gtest/gtest.h"
extern "C" {
    #include "bit_array.h"
}

TEST(bit_array, create_bit_array_10elems) {
    bit_array* b_array = create_bit_array(10);
    ASSERT_EQ(b_array->array_size, 3);
    free_bit_array(b_array);
}

TEST(bit_array, create_bit_array_15elems) {
    bit_array* b_array = create_bit_array(15);
    ASSERT_EQ(b_array->array_size, 4);
    free_bit_array(b_array);
}

TEST(bit_array, setting_and_checking_alternating) {
    size_t bits_count = 15;
    bit_array* b_array = create_bit_array(bits_count);
    for (size_t i = 0; i < bits_count; ++i) {
        set_bit(b_array, i);
        ASSERT_TRUE(check_bit(b_array, i));
    }
    ASSERT_EQ(b_array->array_size, 4);
    free_bit_array(b_array);
}

TEST(bit_array, setting_and_checking_after_loop) {
    size_t bits_count = 15;
    bit_array* b_array = create_bit_array(bits_count);
    for (size_t i = 0; i < bits_count; ++i) {
        set_bit(b_array, i);
    }
    for (size_t i = 0; i < bits_count; ++i) {
        ASSERT_TRUE(check_bit(b_array, i));
    }
    ASSERT_EQ(b_array->array_size, 4);
    free_bit_array(b_array);
}

TEST(bit_array, setting_clearing_and_checking_alternating) {
    size_t bits_count = 15;
    bit_array* b_array = create_bit_array(bits_count);
    for (size_t i = 0; i < bits_count; ++i) {
        set_bit(b_array, i);
        ASSERT_TRUE(check_bit(b_array, i));
        clear_bit(b_array, i);
        ASSERT_FALSE(check_bit(b_array, i));
    }
    free_bit_array(b_array);
}

TEST(bit_array, setting_clearing_and_checking_after_loop) {
    size_t bits_count = 15;
    bit_array* b_array = create_bit_array(bits_count);
    for (size_t i = 0; i < bits_count; ++i) {
        set_bit(b_array, i);
        ASSERT_TRUE(check_bit(b_array, i));
    }
    for (size_t i = 0; i < bits_count; ++i) {
        clear_bit(b_array, i);
    }
    for (size_t i = 0; i < bits_count; ++i) {
        ASSERT_FALSE(check_bit(b_array, i));
    }
    free_bit_array(b_array);
}