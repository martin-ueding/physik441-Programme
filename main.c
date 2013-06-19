// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "aufgabe3.h"
#include "cash-carp.h"
#include "rk4.h"

double phi(double x, double *y, double *a) {
	return y[1];
}

double omega(double x, double *y, double *a) {
	return - a[0] * a[0] * y[0];
}

void problem1() {
	puts("problem1()");
	double h = 1e-3;
	double x = 0.;
	double y[2] = {0., 1.};
	double a[1] = {1.};
	ode f[2] = {phi, omega};
	int n = 2;

	struct state s;
	rk4_init_state(n, &s);

	FILE *fp = fopen("out/1.txt", "w");
	assert(fp);
	while (x <= 100) {
		fprintf(fp, "%15g %15g %15g\n", x, y[0], y[1]);
		rk4(n, h, &x, y, f, a, &s);
	}
	fclose(fp);
}

void problem2() {
	puts("problem2()");
	double h = 1e-3;
	double x = 0.;
	double y[2] = {0., 1.};
	double a[1] = {1.};
	ode f[2] = {phi, omega};
	int n = 2;

	struct cash_carp_state ccs;
	cash_carp_init_state(n, &ccs);

	FILE *fp = fopen("out/2.txt", "w");
	assert(fp);
	while (x <= 100) {
		fprintf(fp, "%15g %15g %15g\n", x, y[0], y[1]);
		cash_carp(n, h, &x, y, f, a, &ccs);
	}
	fclose(fp);
}

int main(void) {
	problem1();
	problem2();
	problem3();

	return 0;
}
