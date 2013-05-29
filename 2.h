// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

/**
 * \file
 */

#ifndef P2_H
#define P2_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double dist(double x);

/**
 * Inverse CDF.
 */
double inverse_cdf(double z);

void problem2();
void problem2a();
void problem2b();

#endif /* end of include guard: P2_H */
