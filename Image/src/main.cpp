#include<iostream>
#include<random>
#include"Image.h"

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    constexpr int width=500;
    constexpr int height=500;

    std::uniform_int_distribution<> randWidth(0,width-1);
    std::uniform_int_distribution<> randHeight(0,height-1);

    std::uniform_int_distribution<unsigned char>colour(0.255);

    std::uniform_real_distribution<float>zeroToOne(0.0f,1.0f);


    Image image(500,500,255,255,255,255);

    for(size_t i = 0; i<500; ++i)
    {
        auto r=colour(gen);
        auto g=colour(gen);
        auto b=colour(gen);
        auto x = randWidth(gen);
        auto y = randHeight(gen);

        for(size_t s=0; s<50; ++s){
            
            auto splat_size = 10;
            auto alpha = 2*M_PI*zeroToOne(gen);
            auto radius = splat_size*sqrtf(zeroToOne(gen));
            auto rx = x +int(radius*cosf(alpha));
            auto ry = y +int(radius*sin(alpha));

            if(rx>=width || ry>=height)
                continue;
            image.setPixel(rx,ry,colour(gen),colour(gen),colour(gen));
        }
       
        
    }

    image.save("ImagePlaygound.jpg");

    return EXIT_SUCCESS;
}