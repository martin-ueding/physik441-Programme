// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgaben.hpp"

void aufgabe1() {
	std::cout << "Aufgabe 1" << std::endl;
	double result = nume::banach_fix(f1, 0., 30);
	std::cout << "Fixpunkt: " << result << std::endl;
}

/**
 @returns @f$ 0.2x^2 + 0.1 x - 5 @f$ 
 */
double f1(double x) {
	return 0.2 * x * x + 0.1 * x - 5;
}
