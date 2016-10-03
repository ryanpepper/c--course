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

void fill_screen(char &particleSymbol, double particlePosition, int maxColumn) {
	screen[static_cast<int>(particlePosition)] = particleSymbol;
}

void draw() {
	std::cout << screen << std::endl;
}




int main() {

  char particleSymbol = '*';
  double particlePosition1 = 0;
  double particlePosition2 = 10;
  double particleSpeed = 6.3;
  int maxColumn = 80;
  int timeStep = 0;
  int stopTime = 60;
  double minColumn = 0;
  while (timeStep < stopTime) {
    clear_buffer();
    move(particlePosition1, particleSpeed, minColumn, maxColumn);
    move(particlePosition2, particleSpeed, minColumn, maxColumn);
    fill_screen(particleSymbol, particlePosition1, maxColumn);
    fill_screen(particleSymbol, particlePosition2, maxColumn);
    draw();
    timeStep++;
  }
}
