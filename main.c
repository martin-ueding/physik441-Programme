// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "splines.h"

int main(int argc, char **argv) {
	FILE *in = fopen("daten06.dat", "r");
	assert(in);
	int count;
	fscanf(in, "%d\n", &count);
	double x[count];
	double y[count];
	for (int i = 0; i < count; i++) {
		fscanf(in, "%lf %lf\n", x+i, y+i);
	}
	fclose(in);

	double coefficients[count][4];
	cubic_spline_interpolate(x, y, 4, coefficients);

	FILE *out = fopen("out/points.csv", "w");
	assert(out);
	for (int i = 0; i < count; i++) {
		fprintf(out, "%f\t%f\n", x[i], y[i]);
	}
	fclose(out);

	out = fopen("out/coefficients.csv", "w");
	assert(out);
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 4; j++) {
			fprintf(out, "%f\t", coefficients[i][j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);

	return 0;
}
