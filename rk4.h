// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file
 */

#ifndef RK4_H
#define RK4_H

#include <stdlib.h>

/**
 State for the rk4() function.

 In the lecture notes, these member variables are declared as \c static inside rk4(). This is bad for the following reasons since the function has side effects. That can hinder:

 \li Unit Testing
 \li Multithreadings
 */
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

/**
 Initializes the members of the \c struct \ref state.

 \param[in] n Number of ODEs to solve
 \param[in, out] s State
 */
void rk4_init_state(int n, struct state *s);

#endif /* end of include guard: RK4_H */
