// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "splines.h"

int main(int argc, char **argv) {
	FILE *in = fopen("daten06.dat", "r");

	int count;
	fscanf(in, "%d\n", &count);

	double *x, *y;
	x = malloc(sizeof(*x) * count);
	y = malloc(sizeof(*y) * count);

	for (int i = 0; i < count; i++) {
		fscanf(in, "%lf %lf\n", x+i, y+i);
	}

	double coefficients[count][4];

	cubic_spline_interpolate(x, y, 4, coefficients);

	return 0;
}
