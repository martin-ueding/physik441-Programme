// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef RK4_H
#define RK4_H

#include <stdlib.h>

struct state {
	double *k1;
	double *k2;
	double *k3;
	double *k4;
	double *yy;
	double xx;
};

typedef double (*ode)(double, double*, double*);

void rk4(int n, double h, double *x, double *y, ode *f, double *a, struct state *s);

void rk4_init_state(int n, struct state *s);

#endif /* end of include guard: RK4_H */
