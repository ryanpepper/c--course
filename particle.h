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
  void move(int, int);
  friend std::istream& operator>>(std::istream &in, Particle &p);
  void fill_screen(Screen&);
  char symbol;
  double position;
  double speed;
};
#endif

