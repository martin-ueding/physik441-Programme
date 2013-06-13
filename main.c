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

void runge_kutta_2d(double omega, char *filename) {
	double h = 0.1;
	double t = 0.;
	double phi = 0;

	double phi_new, omega_new;

	double k[4][2];

	FILE *fp = fopen(filename, "w");
	assert(fp);
	for (t = 0.; t <= 20.; t += h) {

		k[0][0] = dot_phi(t, phi, omega);
		k[0][1] = dot_omega(t, phi, omega);
		phi_new = phi + k[0][0] * h/2.;
		omega_new = omega + k[0][1] * h/2.;

		k[1][0] = dot_phi(t + h/2., phi_new, omega_new);
		k[1][1] = dot_omega(t + h/2., phi_new, omega_new);
		phi_new = phi + k[1][0] * h/2.;
		omega_new = omega + k[1][1] * h/2.;

		k[2][0] = dot_phi(t + h/2., phi_new, omega_new);
		k[2][1] = dot_omega(t + h/2., phi_new, omega_new);
		phi_new = phi + k[2][0] * h/2.;
		omega_new = omega + k[2][1] * h/2.;

		k[3][0] = dot_phi(t + h/2., phi_new, omega_new);
		k[3][1] = dot_omega(t + h/2., phi_new, omega_new);

		phi += (k[0][0] + 2.*k[1][0] + 2.*k[2][0] + k[3][0])* h/6.;
		omega += (k[0][1] + 2.*k[1][1] + 2.*k[2][1] + k[3][1])* h/6.;

		fprintf(fp, "%g\t%g\t%g\n", t, phi, omega);

	}
	assert(fp);
	fclose(fp);
}

int main(int argc, char **argv) {
	runge_kutta_2d(.01, "out/1b-1.txt");
	runge_kutta_2d(1.8, "out/1b-2.txt");
	runge_kutta_2d(1.93, "out/1b-3.txt");
	runge_kutta_2d(2.0, "out/1b-4.txt");

	return 0;
}
