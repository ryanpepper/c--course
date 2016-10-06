#include<iostream>
#include "screen.h"

char& Screen::operator[](const unsigned index) {
  return this->buffer[index];
}

Screen& Screen::operator=(Screen other) {
  std::swap(this->length, other.length);
  std::swap(this->buffer, other.buffer);
  return *this;
}

void swap(Screen first, Screen second) {
    std::swap(first.length, second.length);
    std::swap(first.buffer, second.buffer);
};




Screen::Screen(int l) : length(l) {
  this->buffer = new char[length];
}

Screen::Screen(const Screen& other) : length(other.length) {
  this->buffer = new char[other.length];
  std::cout << "I'm a noisy copy constructor" << std::endl;
  std::copy(other.buffer, other.buffer + other.length, this->buffer);
}

Screen::~Screen(void) {
  delete[] this->buffer;
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
