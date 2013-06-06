// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 * \file
 */

#ifndef SPLINES_H
#define SPLINES_H

#define N 3

#include <assert.h>
#include <stdlib.h>

/**
 Evaluates a cubic spline.

 \param[in] x x-value
 \param[in] x0 x0-value
 \param[in] coefficients Coefficients of the cubic spline (4 entries)
 */
double cubic_spline_eval(double x, double x0, double *coefficients);

/**
 Calculates the coefficients for the given data.

 \param[in] x Array of x values
 \param[in] y Array of y values
 \param[in] data_count Number of entries on the x and y arrays
 \param[out] coefficients Calculates coeffcients
 */
void cubic_spline_interpolate(double *x, double *y, int data_count, double (*coefficients)[4]);

#endif /* end of include guard: SPLINES_H */
