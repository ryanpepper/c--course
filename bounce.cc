// N.B. This program contains a bug, on purpose.

#include <iostream>

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

void draw(char &particleSymbol, double particlePosition, int maxColumn) {
	for (int i = 0; i < particlePosition; i++) {
		std::cout << " ";
	}
	std::cout << particleSymbol << std::endl;
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
