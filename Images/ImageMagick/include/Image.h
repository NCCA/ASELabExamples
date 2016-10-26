#ifndef IMAGE_H_
#define IMAGE_H_

#include <memory>
#include <string>

class Image
{
  public :

    explicit Image(size_t _width, size_t _height, size_t _pixelDepth=3);
    // make sure we can't copy this class as it could be expensive.
    Image(const Image &)=delete;
    Image & operator=(const Image &)=delete;
    void setPixel(size_t _x, size_t _y, unsigned char _r,
                                        unsigned char _g,
                                        unsigned char _b);
    void save(const std::string &_fname);
    void setBackground(unsigned char _r,
                       unsigned char _g,
                       unsigned char _b);
  private :

   std::unique_ptr< unsigned char []> m_data;
   size_t m_width=0;
   size_t m_height=0;
   size_t m_pixelDepth=3;
};


#endif
