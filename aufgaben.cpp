// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "aufgaben.hpp"

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

void aufgabe_a() {
	try {
		double root1 = bisect::bisect(-5.0, 0.0, parabola, 10000, 1.0e-10);
		double root2 = bisect::bisect(0.0, 5.0, parabola, 10000, 1.0e-10);
		std::cout << "Roots " << root1 << ", " << root2 << "\n";
	}
	catch (bisect::NoRootException &e) {
		std::cout << e.what() << std::endl;
	}
}

void aufgabe_b() {
	try {
		double u_d = bisect::bisect(0.0, 100.0, f, 1000000, 1e-6);
		double i_d_ = i_d(u_d);
		std::cout << "U_d = " << u_d << std::endl;
		std::cout << "I_d = " << i_d << std::endl;
	}
	catch (bisect::NoRootException &e) {
		std::cout << e.what() << std::endl;
	}
}
