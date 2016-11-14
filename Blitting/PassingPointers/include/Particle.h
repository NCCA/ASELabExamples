#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Vec2.h"
#include "Image.h"
class Emitter;
class Particle
{
  public :
    Particle(Emitter *_emitter);
    void update();
    void draw(Image &_i) const;
  private :
    Vec2<int> m_pos;
    const Emitter *m_emitter;
    Vec2<int> m_dir;
    int m_life;
    int m_maxLife;
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};


#endif
