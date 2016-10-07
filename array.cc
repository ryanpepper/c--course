#include "array.hh"
#include "particle.h"
#include<algorithm>

Array::Array(): N(0), array(NULL) {}


Array::~Array() {
  delete[] array;
}

Array& Array::operator=(Array other) {
  swap(*this, other);
  return *this;
}



Array::Array(const Array& other) : N(other.N), array(new Particle[other.N]) {
  std::copy(other.array, other.array + N, this->array);
}

void swap(Array &lhs, Array &rhs) {
  using std::swap;
  swap(lhs.array, rhs.array);
  swap(lhs.N, rhs.N);
}

void Array::push_back(Particle &p) {
  Particle *tmp = new Particle[this->N+1];
  std::copy(this->array, this->array+this->N, tmp);
  tmp[this->N] = p;
  this->N++;
  delete[] this->array;
  this->array = tmp;
}

Particle& Array::operator[](const unsigned n) {
  return this->array[n];
}

int Array::size() {
  return this->N;
}
