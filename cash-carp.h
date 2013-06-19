// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file
 */

#ifndef CASH-CARP_H
#define CASH-CARP_H

#include <stdlib.h>

#include "ode.h"

/**
 State for the cash_carp() function.
 */
struct state {
	double *k1;
	double *k2;
	double *k3;
	double *k4;
	double *yy;
	double xx;
};

/**
 Cash-Carp ODE solver.

 Solves a set of \c n ODE.

 \param n[in] Numer of ODE
 \param h[in] Step width
 \param x[in, out] x-coodinate
 \param y[in, out] y-coordinates
 \param a[in] Parameters for the ODE
 \param s[in, out] State of the ODE solver
 */
void cash_carp(int n, double h, double *x, double *y, ode *f, double *a, struct state *s);

/**
 Initializes the members of the \c struct \ref state.

 \param[in] n Number of ODEs to solve
 \param[in, out] s State
 */
void cash_carp_init_state(int n, struct state *s);


#endif /* end of include guard: CASH-CARP_H */
