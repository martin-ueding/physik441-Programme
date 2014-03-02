// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "series.h"

double pi_a(int k) {
	return sqrt(series_a(k) * 6);
}

double pi_b(int k) {
	return pow(series_b(k) * 90, 0.25);
}

double series_a(int k) {
	double sum = 0.0;
	double summand = 1.0;

	for (int n = 1; n <= k; ++n) {
		summand = 1.0 / (n * n);
		sum += summand;
	}

	return sum;
}

double series_b(int k) {
	double sum = 0.0;
	double summand = 1.0;

	for (int n = 1; n <= k; ++n) {
		summand = 1.0 / (n * n * n * n);
		sum += summand;
	}

	return sum;
}
