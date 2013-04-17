// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "bisect.h"

int opposite_signs(double x1, double x2) {
	return ((x1 > 0.0 && x2 < 0.0) || (x1 < 0.0 && x2 > 0.0));
}

double bisect(double a1, double a2, double(*f)(double), int max_iter, double precision) {
	// Check, whether f(a1) and f(a2) have opposite sign.
	int signs = !opposite_signs(f(a1), f(a2));
	if (signs) {
		printf("Error: f(a1) and f(a2) do not have opposite sign!\n");
		assert(signs);
		return NAN;
	}

	double cur = NAN;
	double y1, y2;
	double y_cur;
	double abs_y_cur;

	for (int iter = 0; iter < max_iter; ++iter) {
		cur = (a1 + a2) / 2;
		y1 = f(a1);
		y2 = f(a2);
		y_cur = f(cur);
		abs_y_cur = fabs(y_cur);

		if (abs_y_cur <= precision) {
			// Found a root.
			break;
		}

		if (opposite_signs(y1, y_cur)) {
			// There is a change in sign in the first half of the interval.
			a2 = cur;
		}
		else if (opposite_signs(y2, y_cur)) {
			// There is a change in sign in the second half of the interval.
			a1 = cur;
		}
		else {
			// No root was found.
			return NAN;
		}
	}
	return cur;
}
