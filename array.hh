#ifndef ARRAY_HH
#define ARRAY_HH

#include "particle.h"


template<class T>
class Array {
private:
  T* array;
  unsigned N;
public:
  Array<T>(): N(0), array(NULL) {}

  ~Array<T>() {
    delete[] array;
  }

  Array<T>(const Array& other) : N(other.N), array(new T[other.N]) {
    std::copy(other.array, other.array + N, this->array);
  }

  Array<T>& operator=(Array<T> other) {
    swap(*this, other);
    return *this;
  }

  void push_back(T& p){
    T *tmp = new T[this->N+1];
    std::copy(this->array, this->array+this->N, tmp);
    tmp[this->N] = p;
    this->N++;
    delete[] this->array;
    this->array = tmp;
  }

  template<typename P>
  friend void swap(Array<P> &lhs, Array<P> &rhs);

  T& operator[](const unsigned n) {
    return this->array[n];
  }

  int size() {
    return N;
  }

};

template<typename T>
void swap(Array<T> &lhs, Array<T> &rhs) {
  using std::swap;
  swap(lhs.array, rhs.array);
  swap(lhs.N, rhs.N);
}

#endif



