// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 * \file
 */

#ifndef SPLINES_H
#define SPLINES_H

/**
 Evaluates a cubic spline.
 
 \param x x-value
 \param coefficients Coefficients of the cubic spline (4 entries)
 */
double cubic_spline_eval(double x, double *coefficients);


#endif /* end of include guard: SPLINES_H */
