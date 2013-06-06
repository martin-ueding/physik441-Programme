// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "splines.h"

void cubic_spline_eval_linspace(double min, double max, int steps, double *x, double(*coefficients)[4], int data_count, double *out_x, double *out_y) {
	double step_size = (max - min) / steps;
	double cur;
	int spline_id = 0;

	for (int step = 0; step < steps; step++) {
		cur = min + step_size * step;
		out_x[step] = cur;
		out_y[step] = 0;

		// Advance to the next `spline_id` until `cur` lies on the right of it.
		// `cur` then should lie within this and the next `spline_id`.
		while (cur > x[spline_id]) {
			spline_id++;
		}

		double difference = cur - x[spline_id];
		double parenteses = 1.;

		for (int i = 0; i < N; i++) {
			out_y[step] += coefficients[spline_id][N - i] * parenteses;
			parenteses *= difference;
		}
	}
}

void cubic_spline_interpolate(double *x, double *y, int data_count, double(*coefficients)[4]) {
	double A[data_count];
	double B2[data_count];
	double B[data_count];
	double C[data_count];
	double D2[data_count];
	double D[data_count];
	double h[data_count];
	double X[data_count];
	double y_xx[data_count];

	// XXX Variable `x` might not be needed at all.
	// XXX Variable `C` might not be needed at all.

	// Calculate h.
	for (int i = 0; i < data_count - 1; i++) {
		h[i] = x[i + 1] - x[i];
	}

	// Calculate A, B, C, D.
	for (int i = 1; i < data_count; i++) {
		A[i] = h[i - 1];
	}
	for (int i = 1; i < data_count - 1; i++) {
		B[i] = 2. * (h[i - 1] + h[i]);
	}
	for (int i = 0; i < data_count - 1; i++) {
		C[i] = h[i];
	}
	for (int i = 1; i < data_count - 1; i++) {
		D[i] = 6. / h[i] * (y[i + 1] - y[i]) - 6. / h[i - 1] * (y[i] - y[i - 1]);
	}

	// Transform B, C, D
	B2[0] = B[0];
	D2[0] = D[0];
	for (int i = 1; i < data_count - 1; i++) {
		B2[i] = B[i] - C[i - 1] * A[i] / B[i - 1];
		D2[i] = D[i] - D[i - 1] * A[i] / B[i - 1];
	}

	// Calculate the X.
	X[data_count - 2] = D2[data_count - 1] / B2[data_count - 1];
	for (int i = data_count-3; i >= 1; i--) {
		X[i] = D2[i] / B2[i] - C[i] / B2[i] * X[i + 1];
	}

	// Set the `X` to zero at the border, since there should be vanishing
	// curvature there.
	X[0] = 0.;
	X[data_count -1] = 0.;

	for (int i = 0; i < data_count - 1; i++) {
		y_xx[i] = X[i];
	}

	// Calculate the final coefficients.
	for (int i = 0; i < data_count - 1; i++) {
		coefficients[i][0] = 1. / (6. * h[i]) * (y_xx[i + 1] - y_xx[i]);
		coefficients[i][1] = 1. / 2. * y_xx[i];
		coefficients[i][2] = 1. / h[i] * (y[i + 1] - y[1]) - 1. / 6. * h[i] * (y_xx[i + 1] + 2. * y_xx[i]);
		coefficients[i][3] = y[i];
	}
}
