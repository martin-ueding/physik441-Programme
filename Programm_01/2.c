// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_abs.h"

int main(int argc, char **argv) {
	char filename[] = "sin.csv";
	FILE *fp = fopen(filename, "w");

	for (double x = -20.0; x <= 20.0; x += 0.05) {
		fprintf(fp, "%f\t%f\n", x, my_abs(sin(x) + 0.2));
	}

	fclose(fp);

	return 0;
}
