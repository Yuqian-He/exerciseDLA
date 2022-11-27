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
    for(int i =0;i<1000;++i)//get 100 pixels
    {
       
        if(w.walk() == true)
        {
            if(i %10)
            {
                 //std::cout<<"begin walk"<<'\n';
                w.saveImage(fmt::format("sim.{:04d}.tiff",++frame));
                //w.saveImage("test.jpg");
            }               
        }
        w.resetStart();
    }

    
    w.saveImage("test.tiff");
    return EXIT_SUCCESS;
}