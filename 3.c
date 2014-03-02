// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "3.h"
#include "sphere.h"

double density(double r) {
	return 3e4 * 5 * r + 1.5e5;
}

double free_length(double r) {
	double m_h = 1.67e-27;
	double sigma_t = 6.65e-29;

	return m_h / sigma_t / density(r);
}

void problem3b() {
	double vx, vy, vz;
	int max_iter = 10000;
	int photons = 1000;

	FILE *fp = fopen("out-3b.csv", "w");

	for (double r_rad = 1e-4; r_rad <= 0.02; r_rad *= 1.7) {
		int escaped = 0;
		int escape_steps = 0;

		for (int p = 0; p < photons; p++) {
			double x = 0., y = 0., z = 0.;
			for (int i = 0; i < max_iter; i++) {
				sphere_draw(&vx, &vy, &vz);
				double r = sqrt(x*x + y*y + z*z) / r_rad;
				if (r >= 1.0) {
					escaped++;
					escape_steps += i;
					break;
				}
				double lambda = free_length(r);
				x += lambda * vx;
				y += lambda * vy;
				z += lambda * vz;
			}
		}
		double mean_steps = (double) escape_steps / escaped;
		fprintf(fp, "%15g %5i %15g\n", r_rad, escaped, mean_steps);
	}
	fclose(fp);
}
