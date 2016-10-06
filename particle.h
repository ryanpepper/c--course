#ifndef PARTICLE_H
#define PARTICLE_H
#include "screen.h"

class Particle {
public:
  Particle();
  Particle(char, double, double);
  Particle(const Particle& other);
  void move(int, int);
  void fill_screen(Screen&);
  char symbol;
  double position;
  double speed;
};
#endif

