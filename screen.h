#ifndef SCREEN_H
#define SCREEN_H
#include<algorithm>
class Screen {

public:
  int length;
  Screen(const Screen&);
  Screen(void);
  Screen(int l);
  ~Screen(void);
  friend void swap(Screen, Screen);
  void draw(void);
  void clear_buffer(void);
  char& operator[](const unsigned);
  Screen& operator=(Screen);
  private:
    char *buffer;
};
#endif
