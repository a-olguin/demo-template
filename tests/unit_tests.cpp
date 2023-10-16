#include "CppUTest/TestHarness.h"
#include "../src/worker.hh" 

TEST_GROUP(DemoTestGroup)
{
};

TEST(DemoTestGroup, FirstTest)
{
   CHECK_TRUE(true);
}

TEST(DemoTestGroup, SecondTest)
{
   std::vector<int> input = {3,2,1};
   std::vector<int> check = {1,2,3};
   CHECK_TRUE(check == demo_work::do_work(input));
}