// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "rk4.h"

void rk4(int n, double h, double *x, double *y, ode *f, double *a, struct state *s) {
	int i;

	for (i = 0; i < n; ++i) {
		s->k1[i] = f[i](*x, y, a);
	}

	s->xx = *x + h /2.;

	for (i = 0; i < n; ++i) {
		s->yy[i] = y[i] + s->k1[i] * h/2.;
	}

	for (i = 0; i < n; ++i) {
		s->k2[i] = f[i](s->xx, s->yy, a);
	}

	s->xx = *x + h /2.;

	for (i = 0; i < n; ++i) {
		s->yy[i] = y[i] + s->k2[i] * h/2.;
	}

	for (i = 0; i < n; ++i) {
		s->k3[i] = f[i](s->xx, s->yy, a);
	}

	for (i = 0; i < n; ++i) {
		s->yy[i] = y[i] + s->k3[i] * h/2.;
	}

	s->xx = *x + h;

	for (i = 0; i < n; ++i) {
		s->k4[i] = f[i](s->xx, s->yy, a);
	}

	for (i = 0; i < n; ++i) {
		y[i] += (s->k1[i] + 2.*s->k2[i] + 2*s->k3[i] + s->k4[i])*h/6.;
	}

	*x = *x + h;
}

void rk4_init_state(int n, struct state *s) {
	s->k1 = (double*) malloc(sizeof(double) * n);
	s->k2 = (double*) malloc(sizeof(double) * n);
	s->k3 = (double*) malloc(sizeof(double) * n);
	s->k4 = (double*) malloc(sizeof(double) * n);
	s->yy = (double*) malloc(sizeof(double) * n);
}

