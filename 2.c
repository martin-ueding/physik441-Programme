// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_abs.h"

int main(int argc, char **argv) {
	char filename[] = "2-out.csv";
	FILE *fp = fopen(filename, "w");

	for (double x = -20.0; x <= 20.0; ++x) {
		fprintf(fp, "%f\t%f\n", x, my_abs(sin(x) + 0.2));
	}

	fclose(fp);

	return 0;
}
