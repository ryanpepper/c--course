// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <new>
#include <random>
#include <functional>

void move(double &particlePosition, double &particleSpeed, int minColumn, int maxColumn) {
	particlePosition += particleSpeed;
	if (particlePosition >= maxColumn) {
		particlePosition = 2*maxColumn - particlePosition;
		particleSpeed = -particleSpeed;
	}
	else if (particlePosition <= minColumn) {
		particlePosition = -particlePosition;
		particleSpeed = -particleSpeed;
	}
}

void clear_buffer(char *screen, int length) {
	for (int i = 0; i < length; i++) {
		screen[i] = ' ';
	}
}

void fill_screen(char *screen, int length, char particleSymbol, double particlePosition, int maxColumn) {
	screen[static_cast<int>(particlePosition)] = particleSymbol;
}

void draw(char *screen, int length) {
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

  auto speed = std::bind(std::uniform_real_distribution<double>(-10,10), std::mt19937(time(0)));
  auto pos = std::bind(std::uniform_real_distribution<double>(0, 120), std::mt19937(time(0)));
  auto symgen = std::bind(std::uniform_int_distribution<int>(0, 5), std::mt19937(time(0)));
  char symbol_choices[] = { 'a', 'o', 'x', '*', 'X', 'O'};
  char *symbols = new char[n_particles];
  double *positions = new double[n_particles];
  double *speeds = new double[n_particles];

  for (int i=0; i<n_particles; i++) {
	positions[i] = pos();
	speeds[i] = speed();
	symbols[i] = symbol_choices[symgen()];
  }

  int timeStep = 0;
  int stopTime = 60;
  while (timeStep < stopTime) {
    clear_buffer(screen, max_columns);
    for(int i = 0; i < n_particles; i++) {
    	move(positions[i], speeds[i], min_columns, max_columns);
   	fill_screen(screen, max_columns, symbols[i], positions[i], max_columns);
    }
    draw(screen, max_columns);
    timeStep++;
  }
  delete[] screen;
}
