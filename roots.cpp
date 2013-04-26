// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "roots.hpp"

double nume::banach_fix(double(*f)(double), double start, int max_iter) {
	double result = start;
	for (int i = 0; i < max_iter; ++i) {
		result = f(result);
	}
	return result;
}

ublas::vector<double> nume::newton_rhapson(
		std::function<ublas::vector<double>(ublas::vector<double>)> f,
		std::function<ublas::matrix<double>(ublas::vector<double>)>
		inverse_jacobian, ublas::vector<double> x, int max_iter) {
	for (int iter = 0; iter < max_iter; ++iter) {
		x = x - ublas::prod(inverse_jacobian(x), f(x));
	}
	return x;
}
