#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "math_lib.h"

class MathLibTestFixture : public ::testing::Test
{
protected:

    void SetUp() override
    {
		// Do some job before test run
    }

    void TearDown() override
    {
		// Do some job after test run
    }
};

TEST_F(MathLibTestFixture, AddTwoValues)
{
    EXPECT_EQ(MathLib::add(10.5, 2.5), 13.0);
    EXPECT_TRUE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0));
    EXPECT_FALSE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0001));
}

TEST_F(MathLibTestFixture, SubTwoValues)
{
    EXPECT_NE(MathLib::subtract(10, 7), 4);
    EXPECT_EQ(MathLib::subtract(10, 7), 3);
}

TEST_F(MathLibTestFixture, MultiplyTwoValues)
{
    EXPECT_EQ(MathLib::multiply(10, 7), 70);
    EXPECT_NE(MathLib::multiply(10, 7), 71);
}

TEST_F(MathLibTestFixture, DivideTwoValues)
{
    EXPECT_EQ(MathLib::divide(10, 2), 5);
    EXPECT_NE(MathLib::divide(10, 2), 3);
}

TEST_F(MathLibTestFixture, DivideByZero)
{
    EXPECT_THROW(MathLib::divide(10, 0), std::invalid_argument);
}

TEST_F(MathLibTestFixture, SquareRoot)
{
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(0), 0));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(1.231), 1.1095));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(16), 4));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(123), 11.0905));
    EXPECT_THROW(MathLib::sqrt(-1), std::invalid_argument);
}

TEST_F(MathLibTestFixture, LeastCommonMultiple)
{
    EXPECT_EQ(MathLib::leastCommonMultiple(4, 6), 12);
    EXPECT_EQ(MathLib::leastCommonMultiple(7, 5), 35);
    EXPECT_EQ(MathLib::leastCommonMultiple(10, 5), 10);
    EXPECT_NE(MathLib::leastCommonMultiple(4,6), 3);
}

TEST_F(MathLibTestFixture, IsPrimeTest)
{
    EXPECT_TRUE(MathLib::isPrime(2));
    EXPECT_TRUE(MathLib::isPrime(3));
    EXPECT_FALSE(MathLib::isPrime(4));
    EXPECT_TRUE(MathLib::isPrime(5));
}

TEST_F(MathLibTestFixture, GreatestCommonDivider)
{
    EXPECT_EQ(MathLib::GCD(10, 6), 2);
}

TEST_F(MathLibTestFixture, SolveQuadraticTwoRoots)
{
    // x^2 - 5x + 6 = 0 -> x = 2, x = 3
    std::vector<double> roots = MathLib::solveQuadratic(1.0, -5.0, 6.0);
    ASSERT_EQ(roots.size(), 2);
    std::sort(roots.begin(), roots.end());
    EXPECT_TRUE(MathLib::isEqual(roots[0], 2.0, 0.001));
    EXPECT_TRUE(MathLib::isEqual(roots[1], 3.0, 0.001));
}

TEST_F(MathLibTestFixture, SolveQuadraticOneRoot)
{
    // x^2 - 4x + 4 = 0 -> x = 2
    std::vector<double> roots = MathLib::solveQuadratic(1.0, -4.0, 4.0);
    ASSERT_EQ(roots.size(), 1);
    EXPECT_TRUE(MathLib::isEqual(roots[0], 2.0, 0.001));
}

TEST_F(MathLibTestFixture, SolveQuadraticNoRoots)
{
    // x^2 + x + 5 = 0 -> D < 0
    std::vector<double> roots = MathLib::solveQuadratic(1.0, 1.0, 5.0);
    EXPECT_TRUE(roots.empty());
}

TEST_F(MathLibTestFixture, SolveQuadraticLinearEquation)
{
    // 0*x^2 + 2x - 8 = 0 -> x = 4
    std::vector<double> roots = MathLib::solveQuadratic(0.0, 2.0, -8.0);
    ASSERT_EQ(roots.size(), 1);
    EXPECT_TRUE(MathLib::isEqual(roots[0], 4.0, 0.001));
}

TEST_F(MathLibTestFixture, SolveQuadraticInfiniteSolutions)
{
    // 0*x^2 + 0*x + 0 = 0 -> кидає std::invalid_argument
    EXPECT_THROW(MathLib::solveQuadratic(0.0, 0.0, 0.0), std::invalid_argument);
}