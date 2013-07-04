// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Licensed under The MIT License

#include <assert.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>
#include <math.h>
#include <stdio.h>

#include "aufgabe4.h"

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

void aufgabe4() {
	puts("# Aufgabe 4");

	FILE *infile = fopen("daten10_2.dat", "r");
	assert(infile);
	int size;
	assert(fscanf(infile, "%d\n", &size) == 1);

	double data[2 * size];
	double time;

	for (int i = 0; i < size; i++) {
		assert(fscanf(infile, "%lg %lg\n", &time, data+2*i) == 2);
		IMAG(data, i) = 0.;
	}

	FILE *fp;
	fp = fopen("out/4-raw.txt", "w");
	assert(fp);
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d %g %g\n", i, REAL(data, i), IMAG(data, i));
	}
	fclose(fp);
	fp = NULL;

	gsl_fft_complex_radix2_forward(data, 1, size);

	fp = fopen("out/4-transformed.txt", "w");
	assert(fp);
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d %g %g\n", i, REAL(data, i) / sqrt(size), IMAG(data, i) / sqrt(size));
	}
	fclose(fp);
}
