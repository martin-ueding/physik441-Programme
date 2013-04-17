// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "bisect.h"

/**
 * Test function.
 */
double f(double x) {
	return x*x - x - 2;
}

int main(int argc, char **argv) {
	double (*function)(double);

	return 0;
}
