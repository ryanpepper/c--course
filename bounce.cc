// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <new>
#include <random>
#include <functional>

class Particle {
public:
  char symbol;
  double position;
  double speed;
  void initialise(char, double, double);
};

void Particle::initialise(char sym, double pos, double vel) {
  symbol = sym;
  position = pos;
  speed = vel;
}
			


void move(Particle *particles, const int minColumn, const int maxColumn) {
  particles->position += particles->speed;
  if (particles->position >= maxColumn) {
    particles->position = 2*maxColumn - particles->position;
    particles->speed = -particles->speed;
  }
  else if (particles->position <= minColumn) {
    particles->position = -particles->position;
    particles->speed = -particles->speed;
  }
}

void clear_buffer(char *screen, const int length) {
  for (int i = 0; i < length; i++) {
    screen[i] = ' ';
  }
}

void fill_screen(char *screen, const Particle *particle, const int maxColumn) {
  screen[static_cast<int>(particle->position)] = particle->symbol;
}


void draw(char *screen, const int length) {
  for (int i = 0; i < length; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}




int main() {
  int min_columns = 0;
  int max_columns = 120;
  char *screen = new char[max_columns];
  int n_particles = 4;
  Particle *particles = new Particle[n_particles];
  auto speed = std::bind(std::uniform_real_distribution<double>(-10,10), std::mt19937(time(0)));
  auto pos = std::bind(std::uniform_real_distribution<double>(0, 120), std::mt19937(time(0)));
  auto symgen = std::bind(std::uniform_int_distribution<int>(0, 5), std::mt19937(time(0)));
  char symbol_choices[] = { 'a', 'o', 'x', '*', 'X', 'O'};
  for (int i=0; i<n_particles; i++) {
    Particle temp;
    temp.initialise(symbol_choices[symgen()], pos(), speed());
    particles[i] = temp;
  }
  
  int timeStep = 0;
  int stopTime = 30;
  while (timeStep < stopTime) {
    clear_buffer(screen, max_columns);
    for(int i = 0; i < n_particles; i++) {
      move(&particles[i], min_columns, max_columns);
      fill_screen(screen, &particles[i], max_columns);
    }
    draw(screen, max_columns);
    timeStep++;
  }
  delete[] screen;
}
