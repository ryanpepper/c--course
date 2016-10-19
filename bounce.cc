// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <fstream>
#include <new>
#include <random>
#include <functional>
#include <iterator>
#include <utility>
#include "particle.h"
#include "screen.h"
#include "array.hh"
#include <vector>

int main(){
  char read_p;
  double read_pos;
  double read_vel;
  std::ifstream config("config.yml");
  std::vector<Particle*> particles;
  int min_column = 0;
  int max_column = 100;

  Screen screen(max_column);

  while (config) {
    char kind;
    config >> kind;
    Particle* p;
    if (kind == 'm') {
    p = new MagicParticle;
    } else {
    p = new Particle;
    }
    config >> *p;
    particles.push_back(p);
  }
  int n_particles = particles.size();
  int timeStep = 0;
  int stopTime = 80;
  while (timeStep < stopTime) {
    screen.clear_buffer();
    for(int i = 0; i < n_particles; i++) {
      particles[i]->move(min_column, max_column);
      particles[i]->fill_screen(screen);
    }
    screen.draw();
    timeStep++;
  }
}
