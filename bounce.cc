// N.B. This program contains a bug, on purpose.

#include <iostream>

void move(double *particlePosition, double *particleSpeed, int minColumn, int maxColumn) {
	*particlePosition += *particleSpeed;
	if (*particlePosition >= maxColumn) {
		*particlePosition = 2*maxColumn - *particlePosition;
		*particleSpeed = -*particleSpeed;
	}
	else if (*particlePosition <= minColumn) {
		*particlePosition = -*particlePosition;
		*particleSpeed = -*particleSpeed;
	}
}

int main() {

  std::string particleSymbol = ":)";
  double particlePosition = 0;
  double particleSpeed = 6.3;
  int maxColumn = 80;
  int timeStep = 0;
  int stopTime = 60;
  double minColumn = 0;
  while (timeStep < stopTime) {
    for (int i = 0; i < particlePosition; i++) {
      std::cout << " ";
    }
    move(&particlePosition, &particleSpeed, minColumn, maxColumn);
    std::cout << particleSymbol << std::endl;
    timeStep++;
  }
}
