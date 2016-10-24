#include "Image.h"
#include <Magick++.h>

Image::Image(size_t _width, size_t _height, size_t _pixelDepth)
{
  m_data.reset(new unsigned char[_width*_height*_pixelDepth]);
  m_width=_width;
  m_height=_height;
  m_pixelDepth=_pixelDepth;
}

void Image::setPixel(size_t _x, size_t _y, unsigned char _r,
                                    unsigned char _g,
                                    unsigned char _b)
{
  size_t offset=(_y*m_pixelDepth * m_width) + _x*m_pixelDepth;
  m_data[offset]=_r;
  m_data[offset+1]=_g;
  m_data[offset+2]=_b;

}

void Image::save(const std::string &_fname)
{
  Magick::Image output(m_width,m_height,"RGB",Magick::CharPixel,m_data.get());
    output.depth(16);
    output.write(_fname.c_str());
}

void Image::setBackground(unsigned char _r,
                   unsigned char _g,
                   unsigned char _b)
{
  for(size_t y=0; y<m_height; ++y)
    for(size_t x=0; x<m_width; ++x)
        setPixel(x,y,_r,_g,_b);

}
