// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "bisect.h"

int opposite_signs(double x1, double x2) {
	return ((x1 > 0.0 && x2 < 0.0) || (x1 < 0.0 && x2 > 0.0));
}

double bisect(double a1, double a2, double (*f)(double), int max_iter, double precision) {
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
		
		printf("a1 = %g, cur = %g, a2 = %g, y1 = %g, y_cur = %g (%g), "
				"y2 = %g\n", a1, cur, a2, y1, y_cur, abs_y_cur, y2);

		if (abs_y_cur <= precision) {
			printf("Root found with %g.\n", abs_y_cur);
			break;
		}

		if (opposite_signs(y1, y_cur)) {
			printf("Using a2 = %g\n", a2);
			a2 = cur;
		}
		else if (opposite_signs(y2, y_cur)) {
			printf("Using a1 = %g\n", a1);
			a1 = cur;
		}
		else {
			printf("No root found\n");
			return NAN;
		}
	}
	return cur;
}
