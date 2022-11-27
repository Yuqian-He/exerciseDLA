#include "Image.h"
#include<OpenImageIO/imageio.h>
#include <iostream>
#include<cstring>

Image::Image(size_t _w, size_t _h) : m_width{_w}, m_height{_h}{
    m_pixels = std::make_unique<RGBA []>(m_width*m_height);
}

Image::Image(size_t _w, size_t _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a): Image(_w, _h){
    for(size_t i = 0; i<m_height*m_width; ++i){
        m_pixels[i] = RGBA(_r,_g,_b,_a);
    }
}

RGBA Image::getPixel(size_t _x, size_t _y) const{
    auto index = (_y * m_width) + _x;
    return m_pixels[0];
}

size_t Image::width() const{
    return m_width;
}

size_t Image::height() const{
    return m_height;
}

bool Image::save(std::string_view _fname) const {
    bool success=false;
    using namespace OIIO;
    auto out = ImageOutput::create(_fname.data());
    if(!out){
        return false;
    }
    ImageSpec spec(m_width,m_height,4,TypeDesc::UINT8);
    success = out->open(_fname.data(),spec);
    success = out->write_image(TypeDesc::UINT8,m_pixels.get());
    success = out->close();
    return success;
}


void Image::clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    auto p = RGBA(_r,_g,_b,_a);
    for (size_t i = 0; i<m_width*m_height; i++){
        m_pixels[i] = p;
    }
    std::memset(&m_pixels[0], p.pixel,sizeof(uint32_t)*m_width*m_height);
}

void Image::setPixel(size_t _x, size_t _y,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    if(_x > m_width || _y > m_height)
        return;
    auto index = (_y * m_width) + _x;
    m_pixels[index].set(_r,_g,_b,_a);
}