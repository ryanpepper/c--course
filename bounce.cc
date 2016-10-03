// N.B. This program contains a bug, on purpose.

#include <iostream>

char screen[80];

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

void clear_buffer() {
	for (int i = 0; i < 80; i++) {
		screen[i] = ' ';
	}
}

void draw(char &particleSymbol, double particlePosition, int maxColumn) {
	clear_buffer();
	screen[static_cast<int>(particlePosition)] = particleSymbol;
	std::cout << screen << std::endl;
}

int main() {

  char particleSymbol = '*';
  double particlePosition = 0;
  double particleSpeed = 6.3;
  int maxColumn = 80;
  int timeStep = 0;
  int stopTime = 60;
  double minColumn = 0;
  while (timeStep < stopTime) {
    move(particlePosition, particleSpeed, minColumn, maxColumn);
    draw(particleSymbol, particlePosition, maxColumn);
    timeStep++;
  }
}
