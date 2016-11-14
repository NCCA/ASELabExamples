#ifndef EMITTER_H_
#define EMITTER_H_

#include "Particle.h"
#include "Image.h"
#include <vector>
#include <memory>
class Emitter
{
  public :
    Emitter(Vec2<int> _pos, int _num);
    void update();
    void draw(Image &_i) const;
    Vec2<int> getPos()const  {return m_pos;}
    void moveX(int _dx){ m_pos.m_x+=_dx;}
    void moveY(int _dy){ m_pos.m_y+=_dy;}
  private :
    std::vector <std::unique_ptr <Particle>> m_particles;
    Vec2<int> m_pos;
};



#endif
