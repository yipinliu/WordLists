#include "gtest/gtest.h"
#include "IO.hpp"

TEST(){
    int i = 0;
    EXPECT_EQ(0,i++);
    EXPECT_EQ(1,i++);
    char* p = nullptr;
    EXPECT_EQ(0,fileToStr("../example.cpp",&p));
    EXPECT_NE(nullptr,p);
}