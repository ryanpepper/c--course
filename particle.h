#ifndef PARTICLE_H
#define PARTICLE_H
#include "screen.h"
#include<iostream>
#include<fstream>

class Particle {
public:
  Particle();
  Particle(char, double, double);
  Particle(const Particle& other);
  virtual void move(const int&, const int&);
  friend std::istream& operator>>(std::istream &in, Particle &p);
  void fill_screen(Screen&);
  char symbol;
  double position;
  double speed;
};

class MagicParticle : public Particle {
  using Particle::Particle;
  virtual void move(const int&, const int&);
};



#endif

