// Taken from
// https://www.gnu.org/software/gsl/manual/html_node/Radix_002d2-FFT-routines-for-complex-data.html

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>

#include "aufgabe3.h"

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

void aufgabe3() {
	puts("# Aufgabe 3");

	int i;
	double data[2 * 128];

	for (i = 0; i < 128; i++) {
		REAL(data, i) = 0.0;
		IMAG(data, i) = 0.0;
	}

	REAL(data, 0) = 1.0;

	for (i = 1; i <= 10; i++) {
		REAL(data, i) = REAL(data, 128 - i) = 1.0;
	}

	for (i = 0; i < 128; i++) {
		printf("%d %e %e\n", i, REAL(data, i), IMAG(data, i));
	}
	printf("\n");

	gsl_fft_complex_radix2_forward(data, 1, 128);

	for (i = 0; i < 128; i++) {
		printf("%d %e %e\n", i, REAL(data, i) / sqrt(128), IMAG(data, i) / sqrt(128));
	}
}
