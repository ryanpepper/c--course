// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <new>
#include <random>
#include <functional>
#include <iterator>
#include <utility>
#include "particle.h"
#include "screen.h"

int main(){
  int min_column = 0;
  int max_column = 120;
  Screen screen(max_column);
  int n_particles = 4;
  Particle *particles = new Particle[n_particles];
  auto speed = std::bind(std::uniform_real_distribution<double>(-10,10), std::mt19937(time(0)));
  auto pos = std::bind(std::uniform_real_distribution<double>(0, 120), std::mt19937(time(0)));
  auto symgen = std::bind(std::uniform_int_distribution<int>(0, 5), std::mt19937(time(0)));
  char symbol_choices[] = { 'a', 'o', 'x', '*', 'X', 'O'};
  for (int i=0; i<n_particles; i++) {
    particles[i] = Particle(symbol_choices[symgen()], pos(), speed());
  }
  
  int timeStep = 0;
  int stopTime = 80;
  while (timeStep < stopTime) {
    screen.clear_buffer();
    for(int i = 0; i < n_particles; i++) {
      particles[i].move(min_column, max_column);
      particles[i].fill_screen(screen);
    }
    screen.draw();
    timeStep++;
  }
  delete[] particles;
}
