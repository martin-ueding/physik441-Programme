// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "rk4.h"

double f0(double x, double *y, double *a) {
	return y[1];
}

double f1(double x, double *y, double *a) {
	return - a[0] * a[0] * y[0];
}

int main(void) {
	double h = .05;
	double x = 0.;
	double y[2] = {0., 1.};
	double a[1] = {1.};
	ode f[2] = {f0, f1};
	int n = 2;

	struct state s;
	rk4_init_state(n, &s);

	while (x <= 100) {
		printf("%15g %15g %15g\n", x, y[0], y[1]);
		rk4(n, h, &x, y, f, a, &s);
	}

	return 0;
}
