# include <gtest/gtest.h>

#include "Image.h"


TEST(Image, ctor){
    auto a = Image();
    ASSERT_EQ(a.width(), 0);
    ASSERT_EQ(a.height(), 0);
}

TEST(Image, userCtor){
    auto a = Image(1024,512);
    ASSERT_EQ(a.width(), 1024);
    ASSERT_EQ(a.height(), 512);
}

TEST(Image,userCtorRGB){
    auto a = Image(100,100,255,0,0);
    ASSERT_EQ(a.width(), 100);
    ASSERT_EQ(a.height(), 100);
    auto pixel = a.getPixel(0,0);
    ASSERT_EQ(pixel.r, 255);
    ASSERT_EQ(pixel.g, 0);
    ASSERT_EQ(pixel.b, 0);
    ASSERT_EQ(pixel.a, 255);
}

TEST(Image, clear)
{
    auto a = Image(100,100,255,255,255,0);
    a.save("clear.tiff");
    a.clear(255,0,255,255);
    a.save("clear.tiff");
    for(size_t y=0; y<100; ++y){
        for(size_t x=0; x<100; ++x){
            auto pixel = a.getPixel(x,y);
            ASSERT_EQ(pixel.r, 255);
            ASSERT_EQ(pixel.g, 0);
            ASSERT_EQ(pixel.b, 255);
            ASSERT_EQ(pixel.a, 255);
        }
    }
}

TEST(Image, setPixel){
    auto a = Image(100,100,255,255,255,255);
    for(size_t x = 0; x<100;++x){
        a.setPixel(x,50,255,0,0);
    }
    a.save("redline.tiff");
    for(size_t y = 0; y<100;++y){
         for(size_t x = 0; x<100;++x){
             auto p =  a.getPixel(x,y);
             if(y != 50){
                ASSERT_EQ(p.r, 255);
                ASSERT_EQ(p.g, 255);
                ASSERT_EQ(p.b, 255);
                ASSERT_EQ(p.a, 255);
             }else{
                ASSERT_EQ(p.r, 255);
                ASSERT_EQ(p.g, 0);
                ASSERT_EQ(p.b, 0);
                ASSERT_EQ(p.a, 255);
             }
         }
    }
}

/*
TEST(Image, save)
{
    {
        auto a=Image(512,512,255,0,0);
        EXPECT_TRUE(a.save("red.tiff"));
    }
    {
        auto a=Image(512,512,255,0,255,255);
        EXPECT_TRUE(a.save("green.tiff"));
    }
    
}

/*
TEST(Image, copy){
    auto a = Image(100,200);
    auto b = a;
    ASSERT_EQ(a.width(), 100);
    ASSERT_EQ(a.height(), 200);
    ASSERT_EQ(b.width(), 100);
    ASSERT_EQ(b.height(), 200);
}
*/

