// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

#include <cmath>
#include <iostream>

#include "bisect.hpp"

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

int main(int argc, char **argv) {
	double u_d = bisect(0.0, 100.0, f, 1000000, 1e-6);
	double i_d_ = i_d(u_d);
	std::cout << "U_d = " << u_d << std::endl;
	std::cout << "I_d = " << i_d << std::endl;

	return 0;
}
