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

 \param[in] min Minimal x value to evaluate
 \param[in] max Maximal x value to evaluate
 \param[in] steps Number of points to evaluate
 \param[in] x Data x values, i. e. pivot elements
 \param[in] coefficients Coefficients of the cubic spline (4 entries)
 \param[in] data_count Number of data points in x
 \param[out] out_x Computed x values
 \param[out] out_y Computed y values
 */
void cubic_spline_eval_linspace(double min, double max, int steps, double *x, double(*coefficients)[4], int data_count, double *out_x, double *out_y);

/**
 Calculates the coefficients for the given data.

 \param[in] x Array of x values
 \param[in] y Array of y values
 \param[in] data_count Number of entries on the x and y arrays
 \param[out] coefficients Calculates coeffcients
 */
void cubic_spline_interpolate(double *x, double *y, int data_count, double(*coefficients)[4]);

#endif /* end of include guard: SPLINES_H */
