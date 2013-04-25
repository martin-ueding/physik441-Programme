// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgaben.hpp"

const double half_pi = std::atan(1.) * 2;

void aufgabe1() {
	std::cout << "Aufgabe 1" << std::endl;
	double result = nume::banach_fix(f1, 0., 30);
	std::cout << "Fixpunkt: " << result << std::endl;
}

void aufgabe4() {
	double lower = -2.;
	double upper = 1.;

	double result;

	std::cout << "Aufgabe 4" << std::endl;

	std::ofstream file;
	file.open("out-4.csv");
	for (int n = 1; n < 1000; n++) {
		result = nume::integrate_simpson(f2, lower, upper, n);
		file << n << " " << result << std::endl;
	}
	file.close();
}

void aufgabe5() {
	double l = 1.;
	double g = 9.81;

	std::cout << "Aufgabe 5" << std::endl;

	std::ofstream file;
	file.open("out-5.csv");
	for (double phi0 = 0.0; phi0 <= 1.5; phi0 += 0.05) {
		file << phi0 << " " << t(k2(phi0), l, g) << std::endl;
	}
}

double f1(double x) {
	return 0.2 * x * x + 0.1 * x - 5;
}

double f2(double x) {
	double x2 = x * x;
	double x3 = x2 * x;
	return x3 + 2. * x2 + 0.5 * x + 2;
}

double integrand(double phi, double k2) {
	double s = std::sin(phi);
	return 1. / std::sqrt(1. - k2 * s * s);
}

double k2(double phi0) {
	double s = std::sin(phi0/2.);
	return s * s;
}

double t(double k2, double l, double g) {
	std::function<double(double)> i = std::bind(integrand, std::placeholders::_1, k2);
	return 4. * std::sqrt(l/g) * nume::integrate_simpson(i, 0, half_pi, 1000);
}
