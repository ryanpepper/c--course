#include "particle.h"
#include<iostream>
#include<fstream>

Particle::Particle() {

}


Particle::Particle(char symbol, double position, double speed) : symbol(symbol), position(position), speed(speed) {
}

Particle::Particle(const Particle& other) {
  this->speed = other.speed;
  this->position = other.position;
  this->symbol = other.symbol;
}

void Particle::move(const int &minColumn, const int &maxColumn) {
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

void Particle::fill_screen(Screen& screen) {
  screen[static_cast<int>(this->position)] = this->symbol;
}

std::istream& operator>>(std::istream &in, Particle &p) {
  return in >> p.symbol >> p.position >> p.speed;
}

void MagicParticle::move(const int &minColumn, const int &maxColumn) {
  this->position += this->speed;
  if (this->position>=maxColumn) {
    this->position = 0;
  }
  else if (this->position<=minColumn) {
    this->position = maxColumn;
  }
  std::cout << this->position << std::endl;
}
