// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double e = 1.0;
	while (1 + e != 1) {
		e /= 2;
	}
	e *= 2;
	printf("double: %g\n", e);

	float f = 1.0;
	while (1 + f != 1) {
		f /= 2;
	}
	f *= 2;
	printf("float:  %g\n", f);

	return 0;
}
