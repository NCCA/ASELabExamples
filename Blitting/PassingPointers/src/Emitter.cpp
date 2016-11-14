#include "Emitter.h"


Emitter::Emitter(Vec2<int> _pos, int _num)
{
  m_pos=_pos;
  for(size_t i=0; i<_num; ++i)
    m_particles.emplace_back(new Particle(this));
}

void Emitter::update()
{
  for(auto &p : m_particles)
    p->update();
}

void Emitter::draw(Image &_i) const
{
  for(auto &p : m_particles)
    p->draw(_i);
}

