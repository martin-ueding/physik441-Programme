// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "cash-carp.h"

double a[7][5] = {
	{0., 0., 0., 0., 0.},
	{0., 0., 0., 0., 0.},
	{1./5., 0., 0., 0., 0.},
	{3./40., 9./40., 0., 0., 0.},
	{3./40., -9./10., 6./5., 0., 0.},
	{-11./54., 5./2., -70./27., 35./27., 0.},
	{1631./55296., 175./512., 575./13824, 44275./110592., 253./4096.}
};

void cash_carp(int n, double h, double *x, double *y, ode *f, double *a, struct cash_carp_state *s) {
	int i;

	for (i = 0; i < n; ++i) {
		s->k1[i] = f[i](*x, y, a);
	}

	s->xx = *x + h / 2.;

	for (i = 0; i < n; ++i) {
		s->yy[i] = y[i] + s->k1[i] * h / 2.;
	}

	for (i = 0; i < n; ++i) {
		s->k2[i] = f[i](s->xx, s->yy, a);
	}

	s->xx = *x + h / 2.;

	for (i = 0; i < n; ++i) {
		s->yy[i] = y[i] + s->k2[i] * h / 2.;
	}

	for (i = 0; i < n; ++i) {
		s->k3[i] = f[i](s->xx, s->yy, a);
	}

	for (i = 0; i < n; ++i) {
		s->yy[i] = y[i] + s->k3[i] * h / 2.;
	}

	s->xx = *x + h;

	for (i = 0; i < n; ++i) {
		s->k4[i] = f[i](s->xx, s->yy, a);
	}

	for (i = 0; i < n; ++i) {
		y[i] += (
		            37./378. * s->k1[i]
		            + 250./621. * s->k3[i]
		            + 125./594. * s->k4[i]
		            + 512./1771. * s->k6[i]
		        ) * h;
	}

	*x = *x + h;
}

void cash_carp_init_state(int n, struct cash_carp_state *s) {
	s->k1 = (double *) malloc(sizeof(double) * n);
	s->k2 = (double *) malloc(sizeof(double) * n);
	s->k3 = (double *) malloc(sizeof(double) * n);
	s->k4 = (double *) malloc(sizeof(double) * n);
	s->k5 = (double *) malloc(sizeof(double) * n);
	s->k6 = (double *) malloc(sizeof(double) * n);
	s->yy = (double *) malloc(sizeof(double) * n);
}

