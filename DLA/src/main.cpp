#include <iostream>
#include <cstdlib>
#include "Walker.h"
#include <fmt/format.h>

int main()
{
    Walker w(500,500);
    std::cout<<"DLA \n";
    for(int i = 0; i<10; i++)
    {
        w.randomImageSeed();
    }
    int frame=0;
    for(int i =0;i<10000;++i)
    {
        if(w.walk() == true)
        {
            if(i %10)
                w.saveImage(fmt::format("sim.{:04d}.tiff",++frame));
        }
        w.resetStart();
    }
    w.saveImage("test.jpg");
    return EXIT_SUCCESS;
}