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

void cubic_spline_interpolate(double *x, double *y, int data_count, double (*coefficients)[4]) {
	double *A;
	double *B2;
	double *B;
	double *C;
	double *D2;
	double *D;
	double *h;
	double *X;
	double *y_xx;

	// XXX Variable `x` might not be needed at all.
	// XXX Variable `C` might not be needed at all.

	A = malloc(sizeof(*A) * data_count);
	B = malloc(sizeof(*B) * data_count);
	B2 = malloc(sizeof(*B2) * data_count);
	C = malloc(sizeof(*C) * data_count);
	D = malloc(sizeof(*D) * data_count);
	D2 = malloc(sizeof(*D2) * data_count);
	h = malloc(sizeof(*h) * data_count);
	y_xx = malloc(sizeof(*y_xx) * data_count);

	assert(A);
	assert(B);
	assert(B2);
	assert(C);
	assert(D);
	assert(D2);
	assert(h);
	assert(y_xx);

	// Calculate h.
	for (int i = 0; i < data_count - 1; i++) {
		h[i] = x[i + 1] - x[i];
	}

	// Calculate A, B, C, D.
	for (int i = 1; i < data_count - 1; i++) {
		A[i] = h[i - 1];
	}
	for (int i = 0; i < data_count; i++) {
		B[i] = 2. * (h[i - 1] + h[i]);
	}
	for (int i = 0; i < data_count - 2; i++) {
		C[i] = h[i];
	}
	for (int i = 0; i < data_count - 1; i++) {
		D[i] = 6. / h[i] * (y[i + 1] - y[i]) - 6. / h[i - 1] * (y[i] - y[i - 1]);
	}

	// Transform B, C, D
	B2[0] = B[0];
	D2[0] = D[0];
	for (int i = 1; i < data_count; i++) {
		B2[i] = B[i] - C[i-1] * A[i] / B[i-1];
		D2[i] = D[i] - D[i-1] * A[i] / B[i-1];
	}

	// Calculate the X.
	X[data_count-1] = D2[data_count-1]/B2[data_count-1];
	for (int i = data_count-2; i >= 0; i--) {
		X[i] = D2[i] / B2[i] - C[i] / B2[i] * X[i + 1];
	}

	for (int i = 0; i < data_count - 1; i++) {
		y_xx[i] = X[i];
	}

	// Calculate the final coefficients.
	for (int i = 0; i < data_count - 1; i++) {
		coefficients[i][0] = 1. / (6. * h[i]) * (y_xx[i + 1] - y_xx[i]);
		coefficients[i][1] = 1. / 2. * y_xx[i];
		coefficients[i][2] = 1. / h[i] * (y[i + 1] - y[1]) - 1. / 6. * h[i] * (y_xx[i + 1] + 2. * y[i]);
		coefficients[i][3] = y[i];
	}

	assert(A);
	assert(B);
	assert(B2);
	assert(C);
	assert(D);
	assert(D2);
	assert(h);
	assert(y_xx);

	free(A);
	free(B);
	free(B2);
	free(C);
	free(D);
	free(D2);
	free(h);
	free(y_xx);
}
