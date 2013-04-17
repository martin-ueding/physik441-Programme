// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef BISECT_H
#define BISECT_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Finds a root of the given function.
 *
 * @param a1 Minimal start value
 * @param a2 Maximal start value
 * @param f Function to use
 * @param max_iter Maximal number of iterations
 * @param precision Working precision
 */
double bisect(double a1, double a2, double (*f)(double), int max_iter, double precision);

#endif /* end of include guard: BISECT_H */
