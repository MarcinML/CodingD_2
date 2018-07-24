#include <iostream>
#include "gtest/gtest.h"
#include <gmock/gmock.h>





int main(int argc, char** argv)
{
    int i = 9;
    int& a =i;
    auto && b = a;
    b = 5;
std::cout<<a<<std::endl;

    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

