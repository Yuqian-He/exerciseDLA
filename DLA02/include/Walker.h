#ifndef WALKER_H
#define WALKER_H
#include "Image.h"
#include<memory.h>
#include<string>
#include<random>

class Walker 
{
    public:
        Walker(size_t _w,size_t _h);
        Walker(const Walker &)=default;
        bool saveImage(const std::string &_fname) const;
        void randomImageSeed();
        void resetStart();
        bool walk();

    private: 
        void initRNG();
        std::unique_ptr<Image> m_map;
        std::uniform_int_distribution<> m_xRand;
        std::uniform_int_distribution<> m_yRand;
        int m_xpos;
        int m_ypos;

};

#endif