// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgaben.hpp"

void aufgabe1() {
	std::cout << "Aufgabe 1" << std::endl;
	double result = nume::banach_fix(f1, 0., 30);
	std::cout << "Fixpunkt: " << result << std::endl;
}

void aufgabe4() {
	std::cout << "Aufgabe 4" << std::endl;
	double result = nume::integrate_simpson(f2, 0., 1., 10);
	std::cout << "Integral: " << result << std::endl;
	result = nume::integrate_simpson(parabola, 0., 1., 10);
	std::cout << "Parabalfläche: " << result << std::endl;
}

/**
 @returns @f$ 0.2x^2 + 0.1 x - 5 @f$ 
 */
double f1(double x) {
	return 0.2 * x * x + 0.1 * x - 5;
}

double f2(double x) {
	double x2 = x * x;
	double x3 = x2 * x;
	return x3 + 2. * x2 +0.5*x+2;
}

double parabola(double x) {
	return 0.5 * x*x;
}
