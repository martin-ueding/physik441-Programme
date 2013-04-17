// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "bisect.h"

/**
 * Test function.
 *
 * It has roots at x=-1 and x=2.
 */
double f(double x) {
	return x*x - x - 2;
}

int main(int argc, char **argv) {
	double root = bisect(0.0, 5.0, f, 100, 1e-10);
	printf("Root: %g\n", root);

	return 0;
}
