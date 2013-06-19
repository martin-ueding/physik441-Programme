// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgabe3.h"

double dotphi1(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	return a[0] * (y[2] - y[3] * cos(y[0] - y[1])) / (1 + s * s);
}

double dotphi2(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	return a[0] * (2 * y[3] - y[2] * cos(y[0] - y[1])) / (1 + s * s);
}

double dotp1(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	double s2 = s * s;
	double s22 = (1 + s2) * (1 * s2);

	return - a[0] * y[2] * y[3] * sin(y[0] - y[1]) / (1 + s2)
	       + a[0] * y[2] * y[2] + 2 * y[3] * y[3] - 2 * y[2] * y[3] * cos(y[0] - y[1]) / s22 * sin(y[0] - y[1]) * cos(y[0] - y[1]) - 2 * a[1] * sin(y[0]);
}

double dotp2(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	double s2 = s * s;
	double s22 = (1 + s2) * (1 * s2);

	return a[0] * y[2] * y[3] * sin(y[0] - y[1]) / (1 + s2)
	       - a[0] * y[2] * y[2] + 2 * y[3] * y[3] - 2 * y[2] * y[3] * cos(y[0] - y[1]) / s22 * sin(y[0] - y[1]) * cos(y[0] - y[1]) - a[1] * sin(y[0]);
}
