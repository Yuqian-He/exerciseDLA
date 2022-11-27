#include "Walker.h"
#include <iostream>
#include<random>

std::random_device g_rd;
std::seed_seq g_seed{g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd()};
std::mt19937 g_rng(g_seed);
std::uniform_int_distribution<> g_walkDir(-1,1);
std::uniform_int_distribution<> g_surroundingPoint(1,8);
//char* arrayPoint = new std::vector[];

Walker::Walker(size_t _w, size_t _h)
{
    m_map=std::make_unique<Image>(_w,_h,255,255,255,255);
    initRNG();
    //resetStart();
}

void Walker::initRNG()
{
    m_xRand=std::uniform_int_distribution<>(1,m_map->width()-1);
    m_yRand=std::uniform_int_distribution<>(1,m_map->height()-1);
}

bool Walker::saveImage(const std::string &_fname) const
{
    std::cout<<"Save frame"<<_fname<<"\n";
    return m_map->save(_fname);
}

std::vector<int> Walker::randomImageSeed()
{
    int centrePoint_x = m_xRand(g_rng);
    int centrePoint_y = m_yRand(g_rng);
    m_map->setPixel(m_xRand(g_rng),m_yRand(g_rng),0,0,0,255);
    auto point = std::vector<int>(centrePoint_x,centrePoint_y);
    return point;
}

std::vector<int> Walker::RandomPoint(std::vector<int> centrePoint)
{
    int surroundingPoint_x = centrePoint[0]+g_walkDir(g_rng);
    int surroundingPoint_y = centrePoint[1]+g_walkDir(g_rng);
}

bool Walker::changePointColour(std::vector<int> p)
{
    bool isWalked;
    if(p[0] ==0 || p[0]  >= m_map->width()-1 || p[1]  ==0 || p[1]  >= m_map->height()-1) 
    {
        isWalked = false;
    }else
    {
        RGBA rgba;
        rgba=m_map->getPixel(p[0],p[1]);
        if(static_cast<int>(rgba.a)==255)
        {
            std::cout<<"found seed\n";
            m_map->setPixel(p[0],p[1],0,0,0,255);
            isWalked = true;
        }

    }
    return isWalked;
}

std::vector<int>* Walker::walk(std::vector<int> centrePoint)
{
    int RandomSurroundingPoint = g_surroundingPoint(g_rng);
    for(int i =0; i<RandomSurroundingPoint; i++)
    {
        auto surroundingP = RandomPoint(centrePoint);
        if(changePointColour(surroundingP) == true)
        {
            surroundingPoint_prt[i] = surroundingP;
        }
        else
        {
            continue;
        }
    }
    return surroundingPoint_prt;
}


// bool Walker::walk()
// {
//     bool walking=true;
//     bool found;//have I found anything
//     while(walking)
//     {
//         //move walker
//         m_xpos +=g_walkDir(g_rng);
//         m_ypos +=g_walkDir(g_rng);
//         //m_map->setPixel(m_xpos,m_ypos,255,0,0,255);
//         //have i hit the edges of the map
//         if(m_xpos ==0 || m_xpos >= m_map->width()-1 ||
//          m_ypos ==0 || m_ypos >= m_map->height()-1) 
//          {
//              walking = false;
//              found = false;
//              break;
//          }
         
//          RGBA p;
//          for(int y=-1;y<=1;++y)
//          {
//              for(int x=-1;x<=1;++x)
//              {
//                  p=m_map->getPixel(m_xpos+x,m_ypos+y);
//                  //std::cout<<std::to_string(p.r)<<std::to_string(p.g)<<std::to_string(p.b)<<'\n';
//                  if(static_cast<int>(p.a)==255)
//                  {
//                      std::cout<<"found seed\n";
//                      m_map->setPixel(m_xpos,m_ypos,0,0,0,255);
//                      walking = false;
//                      found = true;
//                      break;
//                  }
//              }
//          }
         
         
//     } 

//     return found;
// }