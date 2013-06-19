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

/**
 The parameters for the functions.

 The indices are the following:

 \li 0: \f$ \frac{1}{m L^2} \f$
 \li 1:	\f$ m g L \f$
 */
a[] = {
	1.,
	1.,
};

double dotphi1(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	return a[0] * (y[2] - y[3] cos(y[0]-y[1]))/(1+s*s);
}

double dotphi2(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	return a[0] * (2y[3] - y[2] cos(y[0]-y[1]))/(1+s*s);
}

double dotp1(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	double s2 = s*s;
	double s22 = (1+s2)*(1*s2);

	return - a[0] * p1 * p2 * sin(phi1 - phi2) / (1+s2) + a[0] (p1*p1 + 2 * p2*p2 - 2*p1*p2*cos(phi1-phi2)/s22 * sin(phi1-phi2) * cos(phi1-phi2)- 2 * a[1] sin(phi1);
}

double dotp2(double x, double *y, double *a) {
	double s = sin(y[0] - y[1]);
	double s2 = s*s;
	double s22 = (1+s2)*(1*s2);

	return a[0] * p1 * p2 * sin(phi1 - phi2) / (1+s2) - a[0] (p1*p1 + 2 * p2*p2 - 2*p1*p2*cos(phi1-phi2)/s22 * sin(phi1-phi2) * cos(phi1-phi2)- a[1] sin(phi1);
}
