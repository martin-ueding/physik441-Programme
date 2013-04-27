// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgaben.hpp"

const double half_pi = std::atan(1.) * 2;

void aufgabe1() {
	std::cout << std::endl;
	std::cout << "Aufgabe 1" << std::endl;

	std::ofstream file;
	file.open("out-1.csv");

	double result;
	for (int n = 1; n <= 30; ++n) {
		result = nume::banach_fix(f1, 5.4, n);
		file << n << " " << result << std::endl;
	}

	std::cout << "Fixpunkt: " << result << std::endl;
}

void aufgabe2() {
	std::cout << std::endl;
	std::cout << "Aufgabe 2" << std::endl;

	ublas::vector<double> x(2);
	x(0) = x(1) = .5;
	x = nume::newton_rhapson(f3, inverse_jacobian, x, 10);
	std::cout << "Fixpunkt: " << x(0) << " " << x(1) << std::endl;
}

void aufgabe4() {
	double lower = -2.;
	double upper = 1.;
	int max_iter = 1000;

	double result;

	std::cout << std::endl;
	std::cout << "Aufgabe 4" << std::endl;

	std::ofstream file;
	file.open("out-4.csv");
	for (int n = 1; n < max_iter; n++) {
		result = nume::integrate_simpson(f2, lower, upper, n);
		file << n << " " << result << std::endl;
	}
	std::cout << "Ergebnis bei " << max_iter << " Durchläufen: " << result <<
	          std::endl;
	std::cout << "Siehe den Plot." << std::endl;
	file.close();
}

void aufgabe5() {
	double l = 1.;
	double g = 9.81;

	std::cout << std::endl;
	std::cout << "Aufgabe 5" << std::endl;

	std::ofstream file;
	file.open("out-5.csv");
	for (double phi0 = 0.0; phi0 <= 1.5; phi0 += 0.05) {
		file << phi0 << " " << t(k2(phi0), l, g) << std::endl;
	}
	std::cout << "Siehe den Plot." << std::endl;
}

double f1(double x) {
	return 0.2 * x * x + 0.1 * x - 5;
}

double f2(double x) {
	double x2 = x * x;
	double x3 = x2 * x;
	return x3 + 2. * x2 + 0.5 * x + 2;
}

ublas::vector<double> f3(ublas::vector<double> x) {
	ublas::vector<double> result(2);
	result(0) = std::pow(x(0), 3) + x(1) - .5;
	result(1) = x(0) * x(0) - x(1) * x(1);
	return result;
}

double integrand(double phi, double k2) {
	double s = std::sin(phi);
	return 1. / std::sqrt(1. - k2 * s * s);
}

ublas::matrix<double> inverse_jacobian(ublas::vector<double> x) {
	ublas::matrix<double> result(2, 2);
	double x12 = x(0) * x(0);
	double determinant = -6. * x12 * x(1) - 2 * x(0);
	result(0, 0) = - 2. * x(1);
	result(0, 1) = - 1.;
	result(1, 0) = - 2. * x(0);
	result(1, 1) = 3. * x12;
	result /= determinant;
	return result;
}

double k2(double phi0) {
	double s = std::sin(phi0 / 2.);
	return s * s;
}

double t(double k2, double l, double g) {
	std::function<double(double)> i = std::bind(integrand, std::placeholders::_1, k2);
	return 4. * std::sqrt(l / g) * nume::integrate_simpson(i, 0, half_pi, 1000);
}
