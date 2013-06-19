// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file
 */

#include "aufgabe3.h"

/**
 The parameters for the functions.

 The indices are the following:

 \li 0: \f$ \frac{1}{m L^2} \f$
 \li 1:	\f$ m g L \f$
 */
double aufgabe3_a[] = {
	1.,
	1.,
};

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
	       + a[0] * (y[2] * y[2] + 2 * y[3] * y[3] - 2 * y[2] * y[3] * cos(y[0] - y[1])) / s22
	       * sin(y[0] - y[1]) * cos(y[0] - y[1]) - 2 * a[1] * sin(y[0]);
}

double dotp2(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	double s2 = s * s;
	double s22 = (1 + s2) * (1 * s2);

	return a[0] * y[2] * y[3] * sin(y[0] - y[1]) / (1 + s2)
	       - a[0] * (y[2] * y[2] + 2 * y[3] * y[3] - 2 * y[2] * y[3] * cos(y[0] - y[1])) / s22
	       * sin(y[0] - y[1]) * cos(y[0] - y[1]) - a[1] * sin(y[1]);
}

double hamiltonian(double *y, double *a) {
	return a[0] / 2. * (y[2] * y[2] + 2 * y[3] * y[3] - 2 * y[2] * y[3] * cos(y[0] - y[1])) / (1 + sin(y[0] - y[1]) * sin(y[0] - y[1])) + a[1] * (4 - 2 * cos(y[0]) - cos(y[1]));
}

void problem3_runge_kutta() {
	puts("problem3_runge_kutta()");
	double h = .01;
	double x = 0.;
	double y[] = {0., .2, 0., 0.};
	ode f[] = {dotphi1, dotphi2, dotp1, dotp2};
	int n = 4;
	struct state ccs;
	rk4_init_state(n, &ccs);
	FILE *fp = fopen("out/3-rk.txt", "w");
	assert(fp);
	while (x <= 10) {
		fprintf(fp, "%15g %15g %15g %15g %15g %15g\n", x, y[0], y[1], y[2], y[3], hamiltonian(y, aufgabe3_a));
		rk4(n, h, &x, y, f, aufgabe3_a, &ccs);
	}
	fclose(fp);
}

void problem3_cash_carp() {
	puts("problem3_cash_carp()");
	double h = .01;
	double x = 0.;
	double y[] = {.2, 0., 0., 0.};
	ode f[] = {dotphi1, dotphi2, dotp1, dotp2};
	int n = 4;
	struct cash_carp_state ccs;
	cash_carp_init_state(n, &ccs);
	FILE *fp = fopen("out/3-cc.txt", "w");
	assert(fp);
	while (x <= 10) {
		fprintf(fp, "%15g %15g %15g %15g %15g %15g\n", x, y[0], y[1], y[2], y[3], hamiltonian(y, aufgabe3_a));
		cash_carp(n, h, &x, y, f, aufgabe3_a, &ccs);
	}
	fclose(fp);
}

void problem3() {
	problem3_runge_kutta();
	problem3_cash_carp();
}
