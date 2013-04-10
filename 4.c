// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

#include "series.h"

int main(int argc, char **argv) {
	char filename_a[] = "pi_a.csv";
	FILE *fp = fopen(filename_a, "w");
	for (int k = 1; k < 10; ++k) {
		fprintf(fp, "%d\t%f\n", k, pi_a(k));
	}
	fclose(fp);

	char filename_b[] = "pi_b.csv";
	fp = fopen(filename_b, "w");
	for (int k = 1; k < 10; ++k) {
		fprintf(fp, "%d\t%f\n", k, pi_b(k));
	}
	fclose(fp);

	return 0;
}
