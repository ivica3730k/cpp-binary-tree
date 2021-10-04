#include <gtest/gtest.h>

int myfunc(int n) {
    return n + 1;
}

TEST(asdfTest, HandlesPositiveInput) {
    EXPECT_EQ(myfunc(1), 2);
    EXPECT_EQ(myfunc(2), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}