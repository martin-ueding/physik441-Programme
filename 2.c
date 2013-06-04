// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "2.h"

double dist(double x) {
	return 0.5 * sin(x - 0.5);
}

double envelope(double x) {
	double pi = 3.141593;

	if (0 <= x && x <= 2.0708) {
		return .3 * x;
	}
	else if (2.0708 <= x && x < 1 + pi) {
		return 1.24248 - .3 * x;
	}
	else {
		return 0.;
	}
}

double inverse_cdf(double z) {
	if (z <= 0.) {
		return 0.;
	}
	else if (0. < z && z < .5) {
		return 2.92855 * sqrt(z);
	}
	else if (.5 < z && z < 1.) {
		return 4.14159 - 2.92855 * sqrt(1 - z);
	}
	else {
		return 1.;
	}
}

void problem2() {
	problem2a();
	problem2b();
}

void problem2a() {
	int max_used = 1000000;
	int iter = 0;
	int used = 0;

	FILE *fp = fopen("out-2a.csv", "w");

	clock_t start = clock();

	for (iter = 0; used < max_used; iter++) {
		double x = rand() / (RAND_MAX + 1.) * 4.;
		double y = rand() / (RAND_MAX + 1.) * .65;

		if (y > dist(x)) {
			continue;
		}

		used++;
		fprintf(fp, "%g\n", x);
	}
	fclose(fp);

	clock_t end = clock();

	printf("2a| Akzeptanzrate: %g\n", (double) used / iter);
	printf("2a| Laufzeit: %d\n", (int) (end-start));
}

void problem2b() {
	int max_used = 1000000;
	int iter = 0;
	int used = 0;

	FILE *fp = fopen("out-2b.csv", "w");

	clock_t start = clock();

	for (iter = 0; used < max_used; iter++) {
		double x = inverse_cdf(rand() / (RAND_MAX + 1.));
		double y = rand() / (RAND_MAX + 1.) * envelope(x);

		if (y > dist(x)) {
			continue;
		}

		used++;
		fprintf(fp, "%g\n", x);
	}
	fclose(fp);

	clock_t end = clock();

	printf("2b| Akzeptanzrate: %g\n", (double) used / iter);
	printf("2b| Laufzeit: %d\n", (int) (end-start));
}
