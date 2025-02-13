#include <gtest/gtest.h>  // Include GoogleTest
#include <cmath>
#include <limits>
#include "../include/prototype.h"

TEST(CalculateExpTest, BaseCases) {
    EXPECT_NEAR(calculate_exp(2.0, 0), 1.0, 1e-9);
    EXPECT_TRUE(std::isnan(calculate_exp(0.0, 0)));
    EXPECT_NEAR(calculate_exp(0.0, 1), 0.0, 1e-9);
    EXPECT_TRUE(std::isnan(calculate_exp(0.0, -1)));
    EXPECT_TRUE(std::isnan(calculate_exp(0.0, -2)));
    EXPECT_NEAR(calculate_exp(2.0, 1), 2.0, 1e-9);
    EXPECT_NEAR(calculate_exp(-2.0, 1), -2.0, 1e-9);
}

TEST(CalculateExpTest, PositiveIntegers) {
    EXPECT_NEAR(calculate_exp(2.0, 2), 4.0, 1e-9);
    EXPECT_NEAR(calculate_exp(2.0, 3), 8.0, 1e-9);
    EXPECT_NEAR(calculate_exp(2.0, 10), 1024.0, 1e-9);
    EXPECT_NEAR(calculate_exp(3.0, 4), 81.0, 1e-9);
    EXPECT_NEAR(calculate_exp(-2.0, 3), -8.0, 1e-9);
    EXPECT_NEAR(calculate_exp(-2.0, 4), 16.0, 1e-9);
}

TEST(CalculateExpTest, NegativeIntegers) {
    EXPECT_NEAR(calculate_exp(2.0, -1), 0.5, 1e-9);
    EXPECT_NEAR(calculate_exp(2.0, -2), 0.25, 1e-9);
    EXPECT_NEAR(calculate_exp(2.0, -3), 0.125, 1e-9);
    EXPECT_NEAR(calculate_exp(3.0, -2), 1.0/9.0, 1e-9);
    EXPECT_NEAR(calculate_exp(-2.0, -1), -0.5, 1e-9);
    EXPECT_NEAR(calculate_exp(-2.0, -2), 0.25, 1e-9);
}

TEST(CalculateExpTest, FractionalBases) {
    EXPECT_NEAR(calculate_exp(0.5, 2), 0.25, 1e-9);
    EXPECT_NEAR(calculate_exp(0.5, -1), 2.0, 1e-9);
    EXPECT_NEAR(calculate_exp(1.5, 2), 2.25, 1e-9);
}

TEST(CalculateExpTest, LargeExponents) {
    EXPECT_NEAR(calculate_exp(2.0, 20), 1048576.0, 1e-9);
    EXPECT_GT(calculate_exp(1.000001, 1000000), 2.71); // Use GT for approximate comparison
}

TEST(CalculateExpTest, EdgeCases) {
    EXPECT_NEAR(calculate_exp(1.0, 100), 1.0, 1e-9);
    EXPECT_NEAR(calculate_exp(-1.0, 100), 1.0, 1e-9);
    EXPECT_NEAR(calculate_exp(-1.0, 101), -1.0, 1e-9);
}

TEST(CalculateExpTest, SmallLargeBases) {
    EXPECT_NEAR(calculate_exp(1e-10, 2), 1e-20, 1e-30);
    EXPECT_NEAR(calculate_exp(1e10, 2), 1e20, 1e-30);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
