// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "cash-carp.h"

double cash_carp_a[7][5] = {
	{0., 0., 0., 0., 0.},
	{0., 0., 0., 0., 0.},
	{1. / 5., 0., 0., 0., 0.},
	{3. / 40., 9. / 40., 0., 0., 0.},
	{3. / 40., -9. / 10., 6. / 5., 0., 0.},
	{ -11. / 54., 5. / 2., -70. / 27., 35. / 27., 0.},
	{1631. / 55296., 175. / 512., 575. / 13824, 44275. / 110592., 253. / 4096.}
};

double c[] = {0., 1. / 5., 3. / 10., 3. / 5., 1., 7. / 8.};

void cash_carp(int n, double h, double *x, double *y, ode *f, double *a, struct
        cash_carp_state *s) {
	int i;
	int step_id;
	int ode_id;

	for (step_id = 1; step_id < 6; ++step_id) {
		for (ode_id = 0; ode_id < n; ++ode_id) {
			s->k[step_id][ode_id] = f[ode_id](*x, y, a);
		}

		s->xx = *x + c[step_id] * h ;

		for (ode_id = 0; ode_id < n; ++ode_id) {
			double y_shift = 0.;
			for (int j = 0; j < step_id - 1; j++) {
				y_shift += cash_carp_a[step_id][j] * s->k[j][ode_id];
			}

			s->yy[ode_id] = y[ode_id] +  h * y_shift;
		}
	}

	for (i = 0; i < n; ++i) {
		y[i] += (
		            37. / 378. * s->k[1][i]
		            + 250. / 621. * s->k[3][i]
		            + 125. / 594. * s->k[4][i]
		            + 512. / 1771. * s->k[6][i]
		        ) * h;
	}

	*x = *x + h;
}

void cash_carp_init_state(int n, struct cash_carp_state *s) {
	s->k = (double **) calloc(7, sizeof(double *));

	for (int i = 0; i < 7; ++i) {
		s->k[i] = (double *) calloc(n, sizeof(double));
	}

	s->yy = (double *) malloc(sizeof(double) * n);
}

