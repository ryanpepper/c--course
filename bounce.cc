// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <new>
#include <random>
#include <functional>

class Screen;

class Particle {
public:
  char symbol;
  double position;
  double speed;
  void initialise(char, double, double);
  void move(int, int);
  void fill_screen(Screen *);
};

class Screen {
public:
  char *buffer;
  int length;
  Screen(int l);
  void draw(void);
  void clear_buffer(void);
  ~Screen(void);
};

void Particle::initialise(char symbol, double position, double speed) {
  this->symbol = symbol;
  this->position = position;
  this->speed = speed;
}

void Particle::move(const int minColumn, const int maxColumn) {
  this->position += this->speed;
  if (this->position >= maxColumn) {
    this->position = 2*maxColumn - this->position;
    this->speed = -this->speed;
  }
  else if (this->position <= minColumn) {
    this->position = -this->position;
    this->speed = -this->speed;
  }
}

Screen::Screen(int l){
  this->length = l;
  this->buffer = new char[length];
}

Screen::~Screen(void) {
  delete[] this->buffer;
}

void Particle::fill_screen(Screen* screen) {
  screen->buffer[static_cast<int>(this->position)] = this->symbol;
}

void Screen::draw() {
  for (int i = 0; i < this->length; i++) {
    std::cout << this->buffer[i];
  }
  std::cout << std::endl;
}

void Screen::clear_buffer() {
  for (int i = 0; i < this->length; i++) {
    this->buffer[i] = ' ';
  }
}




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
    Particle temp;
    temp.initialise(symbol_choices[symgen()], pos(), speed());
    particles[i] = temp;
  }
  
  int timeStep = 0;
  int stopTime = 80;
  while (timeStep < stopTime) {
    screen.clear_buffer();
    for(int i = 0; i < n_particles; i++) {
      particles[i].move(min_column, max_column);
      particles[i].fill_screen(&screen);
    }
    screen.draw();
    timeStep++;
  }
  delete[] particles;
}
