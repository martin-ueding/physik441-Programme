// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "bisect.h"

double bisect(double a1, double a2, double (*f)(double), int max_iter, double precision) {
	double cur = (a1 + a2) / 2;
	for (int iter = 0; abs(f(cur)) > precision && iter < max_iter; ++iter) {
	}
	return cur;
}
