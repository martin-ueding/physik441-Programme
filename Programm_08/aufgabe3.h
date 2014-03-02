// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file

 Functions needed for problem 3.


 The ODEs are numberd like so:

 \li 0: \f$ \dot \phi_1 \f$
 \li 1: \f$ \dot \phi_2 \f$
 \li 2: \f$ \dot p_1 \f$
 \li 3: \f$ \dot p_2 \f$
 */

#ifndef AUFGABE3_H
#define AUFGABE3_H

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "aufgabe3.h"
#include "cash-carp.h"
#include "rk4.h"

double dotphi1(double x, double *y, double *a);
double dotphi2(double x, double *y, double *a);
double dotp1(double x, double *y, double *a);
double dotp2(double x, double *y, double *a);

void problem3();

#endif /* end of include guard: AUFGABE3_H */
