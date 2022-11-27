#include <gtest/gtest.h>

#include "RGBA.h"

TEST(RGBA,contruct)
{
    RGBA a(255,128,0);
    ASSERT_TRUE(a.r ==255);
    ASSERT_TRUE(a.g ==128);
    ASSERT_TRUE(a.b ==0);
    ASSERT_TRUE(a.a ==255);
}

TEST(RGBA,userCtor){
    RGBA a(255,128,0,255);
    ASSERT_TRUE(a.r ==255);
    ASSERT_TRUE(a.g ==128);
    ASSERT_TRUE(a.b ==0);
    ASSERT_TRUE(a.a ==255);
}

TEST(RGBA, set){
    RGBA a;
    a.set(128,24,65,128);
    ASSERT_TRUE(a.r ==128);
    ASSERT_TRUE(a.g ==24);
    ASSERT_TRUE(a.b ==65);
    ASSERT_TRUE(a.a ==128);
}

TEST(RGBA, fromHexString6){
    RGBA a("FF7F3F");

    ASSERT_TRUE(a.r == 255);

    ASSERT_TRUE(a.g == 127);
    ASSERT_TRUE(a.b == 63);
    //ASSERT_TRUE(a.a == 255);
    
}

TEST(RGBA, fromHexString8){
    RGBA a("FF7F3FFD");

    ASSERT_TRUE(a.r == 255);

    ASSERT_TRUE(a.g == 127);
    ASSERT_TRUE(a.b == 63);
    ASSERT_TRUE(a.a == 253);
    
}