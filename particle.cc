Particle::Particle() {

}


Particle::Particle(char symbol, double position, double speed) : symbol(symbol), position(position), speed(speed) {
}

Particle::Particle(const Particle& other) {
  this->speed = other.speed;
  this->position = other.position;
  this->symbol = other.symbol;
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

void Particle::fill_screen(Screen& screen) {
  screen[static_cast<int>(this->position)] = this->symbol;
}