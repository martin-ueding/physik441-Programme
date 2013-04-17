// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

#include <iostream>

#include "bisect.hpp"

/**
 * Test function.
 *
 * It has roots at x=-1 and x=2.
 */
double parabola(double x) {
	return x * x - x - 2;
}

double i_d(double u_d) {
	double i_s = 1.0e-10;
	double m = 1.5;
	double u_t = 259.0e-3;

	return i_s * exp(u_d / (m * u_t));
}

double f(double u_d) {
	double r = 100.0;
	double u0 = 6.0;

	return u0 - u_d - r * i_d(u_d);
}

int aufgabe_a() {
	double root1 = bisect(-5.0, 0.0, parabola, 10000, 1.0e-10);
	double root2 = bisect(0.0, 5.0, parabola, 10000, 1.0e-10);
	std::cout << "Roots " << root1 << root2 << "\n";
	return 0;
}

int aufgabe_b() {
	double u_d = bisect(0.0, 100.0, f, 1000000, 1e-6);
	double i_d_ = i_d(u_d);
	std::cout << "U_d = " << u_d << std::endl;
	std::cout << "I_d = " << i_d << std::endl;

	return 0;
}

int main(int argc, char **argv) {
	aufgabe_a();
	aufgabe_b();
}
