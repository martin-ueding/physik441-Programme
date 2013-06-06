// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "splines.h"

int main(int argc, char **argv) {

	double x[] = {1., 2., 3., 4.};
	double y[] = {0., 3., 2., -1.};

	double coefficients[4][4];

	cubic_spline_interpolate(x, y, 4, coefficients);

	return 0;
}
