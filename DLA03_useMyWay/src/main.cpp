#include <iostream>
#include <cstdlib>
#include "Walker.h"
#include <fmt/format.h>

int main()
{
    Walker w(500,500);
    std::cout<<"DLA \n";
    int sizeCentrePoint = 10;
    std::vector<int>* DynamicArr = new std::vector<int>[sizeCentrePoint]();
    for(int i = 0; i<sizeCentrePoint; i++)
    {
        auto centrePoint = w.randomImageSeed();
        std::cout<<centrePoint[0]<<" "<<centrePoint[1]<<'\n';
        DynamicArr[i]=centrePoint;
    }


    int numberOfImage = 5;
    
    
    for(int i = 0; i < numberOfImage; i++)
    {
        std::vector<int>** prtArray = new std::vector<int>*[DynamicArr->size()]();
        int sizePointer_prt;
        //std::vector<int>* new_DynamicArrPoint = new std::vector<int>[sizeCentrePoint]();
        if(i == 0)
        {
            //std::vector<int>** prtArray = new std::vector<int>*[DynamicArr->size()]();
            for(int j = 0; j< DynamicArr->size(); j++)
            {
                prtArray[j]=w.walk(DynamicArr[j]);
            }
            for(int z = 0; z< DynamicArr->size(); z++)
            {
                sizePointer_prt=DynamicArr->size();
                sizeCentrePoint = 0;
                sizeCentrePoint += prtArray[z]->size();
            }
        }
        else{
            std::vector<int>** new_prtArray = new std::vector<int>*[sizeCentrePoint]();
            int size = 0;
            for(int j=0; j< sizePointer_prt; j++)
            {               
                for(int z = 0; z< prtArray[j]->size(); z++)
                {
                    new_prtArray[j]=w.walk(prtArray[j][z]);
                    size+= new_prtArray[j]->size();
                }
            }
            sizeCentrePoint=size;
        }
        w.saveImage(fmt::format("sim.{:04d}.tiff",i));
    }
    
    // int frame=0;
    // for(int i =0;i<1000;++i)//get 100 pixels
    // {
       
    //     if(w.walk() == true)
    //     {
    //         if(i %10)
    //         {
    //              //std::cout<<"begin walk"<<'\n';
    //             w.saveImage(fmt::format("sim.{:04d}.tiff",++frame));
    //             //w.saveImage("test.jpg");
    //         }               
    //     }
    //     w.resetStart();
    // }

    
    //w.saveImage("test.tiff");
    return EXIT_SUCCESS;
}