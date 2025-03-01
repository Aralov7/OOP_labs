#include <gtest/gtest.h>
#include "../tests/test_func.cpp"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(test_func("3 < 2") == false);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(test_func("1 + 3 == 10") == true); // равно, ибо шестиричная система, а не десятичная
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(test_func("1 < 3") == true);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(test_func("121 > 231") == false);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(test_func("121 != 231") == true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
 
}