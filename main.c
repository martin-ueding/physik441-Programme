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
		fprintf(out, "%15f\t%15f\n", x[i], y[i]);
	}
	fclose(out);

	out = fopen("out/coefficients.csv", "w");
	assert(out);
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 4; j++) {
			fprintf(out, "%15f\t", coefficients[i][j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);

	int sample_steps = 1000;
	double out_x[sample_steps];
	double out_y[sample_steps];
	cubic_spline_eval_linspace(400., 800., sample_steps, x, coefficients, count, out_x, out_y);

	out = fopen("out/interpolated.csv", "w");
	assert(out);
	for (int i = 0; i < sample_steps; i++) {
		fprintf(out, "%15f\t%15f\n", out_x[i], out_y[i]);
	}
	fclose(out);

	return 0;
}
