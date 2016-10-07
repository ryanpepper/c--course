#ifndef ARRAY_HH
#define ARRAY_HH

#include "particle.h"


class Array {
private:
  Particle* array;
  unsigned N;
public:
  Array();
  ~Array();
  Array(const Array&);
  Array& operator=(Array other);
  void push_back(Particle&);
  friend void swap(Array &lhs, Array &rhs);
  Particle& operator[](const unsigned n);
  int size();
};




#endif


