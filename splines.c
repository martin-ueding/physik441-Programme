// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "splines.h"

double cubic_spline_eval(double x, double x0, double *coefficients) {
	double result = 0.;
	double difference = x - x0;
	double parenteses = 1.;

	for (int i = 0; i < N; i++) {
		result += coefficients[N - i] * parenteses;
		parenteses *= difference;
	}

	return result;
}

void cubic_spline_interpolate(double *x, double *y, int data_count, double **coefficients) {
	double *a;
	double *b;
	double *c;
	double *d;
	double *h;
	double *y_xx;
   
	a = malloc(sizeof(*a) * data_count);
	b = malloc(sizeof(*b) * data_count);
	c = malloc(sizeof(*c) * data_count);
	d = malloc(sizeof(*d) * data_count);
	h = malloc(sizeof(*h) * data_count);
	y_xx = malloc(sizeof(*y_xx) * data_count);

	assert(a);
	assert(b);
	assert(c);
	assert(d);
	assert(h);
	assert(y_xx);

	for (int i = 0; i < N-1; i++) {
		h[i] = x[i+1] - x[i];
	}

	for (int i = 0; i < N-1; i++) {
		a[i] = 1./(6. * h[i]) * (y_xx[i+1] - y_xx[i]);
		b[i] = 1./2. * y_xx[i];
		c[i] = 1./h[i] * (y[i+1] - y[1]) - 1./6. * h[i] * (y_xx[i+1] + 2. * y[i]);
		d[i] = y[i];
	}

	free(a);
	free(b);
	free(c);
	free(d);
	free(h);
	free(y_xx);
}
