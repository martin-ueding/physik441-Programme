// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef SERIES_H
#define SERIES_H

#include <math.h>

/**
 * Calculates pi using the series a.
 *
 * @param k Number of summands to consider
 * @return Approximated value of pi
 */
double pi_a(int k);

/**
 * Calculates pi using the series b.
 *
 * @param k Number of summands to consider
 * @return Approximated value of pi
 */
double pi_b(int k);

/**
 * Calculates the value of the series in equation (3)
 *
 * @param k Number of summands to consider
 * @return Approximated value of series
 */
double series_a(int k);

/**
 * Calculates the value of the series in equation (4)
 *
 * @param k Number of summands to consider
 * @return Approximated value of series
 */
double series_b(int k);

#endif /* end of include guard: SERIES_H */
