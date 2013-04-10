// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "series.h"

double pi_a(int k) {
	return sqrt(series_a(k) * 6);
}

double pi_b(int k) {
	return sqrt(series_a(k) * 90);
}

double series_a(int k) {
	double sum = 0.0;
	double summand = 1.0;

	for (int n = 1; n <= k; ++n) {
		summand /= n * n;
		sum += summand;
	}

	return sum;
}
