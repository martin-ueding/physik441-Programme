// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <cstdlib>
#include <ctime>
#include <iostream>

void aufgabe1() {
	double max = 1.;
	double min = -1.;
	int max_iter = 10000;
	int n = 0;
	double x;
	double y;

	int in_circle = 0;

	std::srand(std::time(NULL));

	for (n = 0; n < max_iter; ++n) {
		x = ((double) std::rand() / (RAND_MAX)) * (max-min) + min;
		y = ((double) std::rand() / (RAND_MAX)) * (max-min) + min;

		//std::cout << x << " " << y << std::endl;

		if (x*x + y*y <= 1) {
			++in_circle;
		}
	}

	std::cout << 4. * in_circle / max_iter << std::endl;

}

int main() {
	aufgabe1();

	return 0;
}
