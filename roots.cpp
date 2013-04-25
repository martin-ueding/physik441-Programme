// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "roots.hpp"

double nume::banach_fix(double (*f)(double), double start, int max_iter) {
	double result = start;
	for (int i = 0; i < max_iter; ++i) {
		result = f(result);
		std::cout << result << std::endl;
	}
	return result;
}
