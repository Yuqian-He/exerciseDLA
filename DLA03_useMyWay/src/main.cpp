#include <iostream>
#include <cstdlib>
#include "Walker.h"
#include <fmt/format.h>

int main()
{
    Walker w(200,200);
    std::cout<<"DLA \n";
    int sizeCentrePoint = 3;
    std::vector<std::vector<int>> DynamicArr;

    //random create start point
    for(int i = 0; i<sizeCentrePoint; i++)
    {
        auto centrePoint = w.randomImageSeed();
        //std::cout<<centrePoint[0]<<" "<<centrePoint[1]<<'\n';
        DynamicArr.push_back(centrePoint);
    }


    //std::cout<<DynamicArr.size()<<"11111111111111"<<'\n';
    w.saveImage("test.tiff");
    int numberOfImage = 5;
    std::vector<std::vector<int>>* prtArray = new std::vector<std::vector<int>>[DynamicArr.size()]();
    
    //every Image
    for(int i = 0; i < numberOfImage; ++i)
    {
        
        int sizePointer_prt;
        //std::vector<int>* new_DynamicArrPoint = new std::vector<int>[sizeCentrePoint]();
        if(i == 0)
        {
            sizeCentrePoint=0;
            //std::vector<int>** prtArray = new std::vector<int>*[DynamicArr->size()]();
            for(int j = 0; j< DynamicArr.size(); ++j)
            {
                prtArray[j]=w.walk(DynamicArr[j]);
                std::cout<<prtArray[j].size()<<"   888888888888888888888888888"<<'\n';
            }
            for(int z = 0; z< DynamicArr.size(); ++z)
            {
                sizePointer_prt=DynamicArr.size();
                //sizeCentrePoint = 0;
                sizeCentrePoint += prtArray[z].size();
            }
            //std::cout<<sizeCentrePoint<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<'\n';
        }
        else{
            std::vector<std::vector<int>>* new_prtArray = new std::vector<std::vector<int>>[sizeCentrePoint]();
            int size = 0;
            //std::cout<<sizePointer_prt<<"2222222222222222222"<<prtArray[0].size()<<'\n';
            for(int j=0; j< sizePointer_prt; ++j)
            {               
                for(int z = 0; z< prtArray[j].size(); ++z)
                {
                    new_prtArray[j]=w.walk(prtArray[j][z]);
                    size+= new_prtArray[j].size();
                    std::cout<<new_prtArray[j].size()<<'\n';
                }
                std::cout<<size<<'\n';
            }
            sizeCentrePoint=size;
            sizePointer_prt=new_prtArray->size();
            prtArray->clear();
            prtArray=new_prtArray;
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