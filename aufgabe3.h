
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


#include <math.h>

/**
 The parameters for the functions.

 The indices are the following:

 \li 0: \f$ \frac{1}{m L^2} \f$
 \li 1:	\f$ m g L \f$
 */
double aufgabe3_a[] = {
	1.,
	1.,
};

double dotphi1(double x, double *y, double *a);
double dotphi2(double x, double *y, double *a);
double dotp1(double x, double *y, double *a);
double dotp2(double x, double *y, double *a);

#endif /* end of include guard: AUFGABE3_H */
