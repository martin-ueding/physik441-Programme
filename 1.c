// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "1.h"

double f1(double x) {
	return 1 / pow(1 + x*x, 4./3.);
}

double integrate_simpson(double (*f)(double), double lower, double upper, int section_count) {
	double result = 0.;

	double section_width = (upper - lower) / section_count;

	for (int section_id = 0; section_id <= section_count; ++section_id) {
		double x = lower + section_width * section_id;
		if (section_id == 0 || section_id == section_count) {
			result += f(x);
		}
		else if (section_id % 2 != 0) {
			result += 4 * f(x);
		}
		else {
			result += 2 * f(x);
		}
	}

	result *= section_width / 3;

	return result;
}

void problem1() {
	int k = 0;

	double integral = 0;
	double step = 0;
	double step_old;

	FILE *fp = fopen("out-1a.txt", "w");
	fprintf(fp, "#%4s %5s %15s %15s\n", "k", "n", "step", "integral");
	do {
		int n = 2;
		do {
			step_old = step;
			step = integrate_simpson(f1, 100 * k, 100 * (k+1), n);
			n *= 2;
			fprintf(fp, "%5i %5i %15g %15g\n", k, n, step, integral);
		} while (fabs(step - step_old) > 1e-10);
		integral += step;
		k++;
	} while (fabs(step) >= 1e-5);
	fclose(fp);
}
