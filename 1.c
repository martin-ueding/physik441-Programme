// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

#include <stdio.h>
#include <stdlib.h>

#include "bisect.h"

/**
 * Test function.
 *
 * It has roots at x=-1 and x=2.
 */
double f(double x) {
	return x * x - x - 2;
}

int main(int argc, char **argv) {
	double root1 = bisect(-5.0, 0.0, f, 10000, 1.0e-10);
	double root2 = bisect(0.0, 5.0, f, 10000, 1.0e-10);
	printf("Roots: %g, %g\n", root1, root2);

	return 0;
}
