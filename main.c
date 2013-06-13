// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double dot_phi(double t, double phi, double omega) {
	return omega;
}

double dot_omega(double t, double phi, double omega) {
	return - sin(phi);
}

double dot_omega_simple(double t, double phi, double omega) {
	return - phi;
}

void runge_kutta_2d_step(double t, double *phi, double *omega, double h,
        double(*dot_phi)(double, double, double),
        double(*dot_omega)(double, double, double)) {
	double phi_new, omega_new;

	static double k[4][2];
	k[0][0] = dot_phi(t, *phi, *omega);
	k[0][1] = dot_omega(t, *phi, *omega);
	phi_new = *phi + k[0][0] * h / 2.;
	omega_new = *omega + k[0][1] * h / 2.;

	k[1][0] = dot_phi(t + h / 2., phi_new, omega_new);
	k[1][1] = dot_omega(t + h / 2., phi_new, omega_new);
	phi_new = *phi + k[1][0] * h / 2.;
	omega_new = *omega + k[1][1] * h / 2.;

	k[2][0] = dot_phi(t + h / 2., phi_new, omega_new);
	k[2][1] = dot_omega(t + h / 2., phi_new, omega_new);
	phi_new = *phi + k[2][0] * h / 2.;
	omega_new = *omega + k[2][1] * h / 2.;

	k[3][0] = dot_phi(t + h / 2., phi_new, omega_new);
	k[3][1] = dot_omega(t + h / 2., phi_new, omega_new);

	*phi += (k[0][0] + 2.*k[1][0] + 2.*k[2][0] + k[3][0]) * h / 6.;
	*omega += (k[0][1] + 2.*k[1][1] + 2.*k[2][1] + k[3][1]) * h / 6.;
}

void runge_kutta_2d(double omega, char *filename,
        double(*dot_phi)(double, double, double),
        double(*dot_omega)(double, double, double)) {
	double h = 0.1;
	double t = 0.;
	double phi = 0;
	double e;

	FILE *fp = fopen(filename, "w");
	assert(fp);
	for (t = 0.; t <= 20.; t += h) {
		runge_kutta_2d_step(t, &phi, &omega, h, dot_phi, dot_omega);
		e = .5 * omega * omega - cos(phi);
		fprintf(fp, "%g\t%g\t%g\t%g\n", t, phi, omega, e);
	}
	fclose(fp);
}

void runge_kutta_2d_tolerance(double omega, char *filename,
        double(*dot_phi)(double, double, double),
        double(*dot_omega)(double, double, double), double tolerance) {
	double h = 0.1;
	double t = 0.;
	double phi = 0.;
	double phi_half;
	double omega_half;
	double d, d_phi, d_omega;

	int steps = 0;

	FILE *fp = fopen(filename, "w");
	assert(fp);
	for (t = 0.; t <= 20.; t += h) {
		do {
			phi_half = phi;
			omega_half = omega;
			runge_kutta_2d_step(t, &phi, &omega, h, dot_phi, dot_omega);
			runge_kutta_2d_step(t, &phi_half, &omega_half, h / 2., dot_phi, dot_omega);
			d_phi = fabs((phi - phi_half) / (1 - 1. / 16));
			d_omega = fabs((omega - omega) / (1 - 1. / 16));
			d = d_phi > d_omega ? d_phi : d_omega;
			h = .8 * h * pow(tolerance / d, 1. / 5.);
		}
		while (d > tolerance);
		fprintf(fp, "%g\t%g\t%g\t%g\n", t, phi, omega, h * 2);
		steps++;
	}
	fclose(fp);

	printf("1e| Schritte bei Toleranz %6.4f: %4d\n", tolerance, steps);
}

int main(int argc, char **argv) {
	runge_kutta_2d(.01, "out/1b-1.txt", dot_phi, dot_omega);
	runge_kutta_2d(1.8, "out/1b-2.txt", dot_phi, dot_omega);
	runge_kutta_2d(1.93, "out/1b-3.txt", dot_phi, dot_omega);
	runge_kutta_2d(2.0, "out/1b-4.txt", dot_phi, dot_omega);

	runge_kutta_2d_tolerance(1.0, "out/1d-0.txt", dot_phi, dot_omega_simple, 1.);
	runge_kutta_2d_tolerance(1.0, "out/1d-1.txt", dot_phi, dot_omega_simple, .1);
	runge_kutta_2d_tolerance(1.0, "out/1d-2.txt", dot_phi, dot_omega_simple, .01);

	return 0;
}
