// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "sphere.h"

#define TESTMAX 1000

double pi = 3.141593;

void hammer_aitov(double *input, double *output) {
	for (int i = 0; i < TESTMAX; i++) {
		double x = input[3*i];
		double y = input[3*i + 1];
		double z = input[3*i + 2];

		double r = sqrt(x*x + y*y + z*z);
		double phi = atan2(y, x);
		double theta = acos(z/r);

		double b = pi/2 - theta;
		double l = phi <= pi ? phi : - pi + phi - pi;

		double denominator = sqrt(1 + cos(b) * sin(l/2));

		double xx = 2 * sqrt(2) * cos(b) * sin(l/2) / denominator;
		double yy = sqrt(2) * sin(b) / denominator;

		output[2*i] = xx;
		output[2*i + 1] = yy;
	}
}

void sphere_draw(double *x, double *y, double *z) {
	double theta = acos((double) rand() / RAND_MAX * 2. - 1.);
	double phi = (double) rand() / RAND_MAX * 2. * pi;

	*x = sin(theta) * cos(phi);
	*y = sin(theta) * sin(phi);
	*z = cos(theta);
}

void test_sphere_draw() {
	double data[TESTMAX * 3];
	double transformed[TESTMAX * 2];

	for (int i = 0; i < TESTMAX; i++) {
		sphere_draw(data + 3*i, data + 3*i + 1, data + 3*i + 2);
	}

	hammer_aitov(data, transformed);

	FILE *out;
	out = fopen("out-3a-data.csv", "w");
	for (int i = 0; i < TESTMAX; i++) {
		fprintf(out, "%f %f\n", data[3*i], data[3*i + 2]);
	}
	fclose(out);

	out = fopen("out-3a-transformed.csv", "w");
	for (int i = 0; i < TESTMAX; i++) {
		fprintf(out, "%f %f\n", transformed[2*i], transformed[2*i + 1]);
	}
	fclose(out);
}
