#include <gtest/gtest.h>
#include "../include/lab1.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(countVowels("awawr")==2);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(countVowels("aaa  wwew    yy")==6);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(countVowels("rtgrtg  rthlk")==0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}