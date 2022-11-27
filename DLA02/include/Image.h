#ifndef IMAGE_H
#define IMAGE_H

#include<cstddef>
#include "RGBA.h"
#include <memory>
#include<string_view>

class Image{
    public:
        Image() = default;
        Image(size_t _w, size_t _h);
        Image(size_t _w, size_t _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a=255);
        size_t width() const;
        size_t height() const;
        RGBA getPixel(size_t _x, size_t _y) const;
        bool save(std::string_view fname)const;
        void clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a=255);
        void setPixel(size_t _x, size_t _y,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a=255);


    private:
        size_t m_width=0;
        size_t m_height=0;
        std::unique_ptr<RGBA []> m_pixels;


};

# endif