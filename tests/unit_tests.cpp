#include "CppUTest/TestHarness.h"
TEST_GROUP(DemoTestGroup)
{
};

TEST(DemoTestGroup, FirstTest)
{
   CHECK_TRUE(true);
}

TEST(DemoTestGroup, SecondTest)
{
   CHECK_TRUE(true);
}