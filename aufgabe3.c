// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file
 */

#include "aufgabe3.h"

/**
 The parameters for the functions.

 The indices are the following:

 http://www.myphysicslab.com/dbl_pendulum.html

 \li 0: \f$ g \f$
 \li 0: \f$ m \f$
 \li 0: \f$ L \f$
 */
double aufgabe3_a[3];

/**
 First angular velocity.

 \f[ \dot \phi_1 = \ldots \f]
 */
double dotphi1(double x, double *y, double *a) {
	//double phi1 = y[0];
	//double phi2 = y[1];
	double omega1 = y[2];
	//double omega2 = y[3];

	//double g = a[0];
	//double m = a[1];
	//double L = a[2];

	return omega1;
}

/**
 Second angular velocity.

 \f[ \dot \phi_2 = \ldots \f]
 */
double dotphi2(double x, double *y, double *a) {
	//double phi1 = y[0];
	//double phi2 = y[1];
	//double omega1 = y[2];
	double omega2 = y[3];

	//double g = a[0];
	//double m = a[1];
	//double L = a[2];

	return omega2;
}

/**
 First momentum.

 \f[ \dot p_1 = \ldots \f]
 */
double dotp1(double x, double *y, double *a) {
	double phi1 = y[0];
	double phi2 = y[1];
	double omega1 = y[2];
	double omega2 = y[3];

	double g = a[0];
	double m = a[1];
	double L = a[2];

	return (
			- g * (2* m + m) * sin(phi1) - m * g * sin(phi1 - 2.*phi2) - 2.* sin(phi1-phi2) * m * (omega2*omega2 * L + omega1*omega1 *L*cos(phi1-phi2))
		   )
		/ (
				L * (2.*m + m - m * cos(2. * phi1 - 2. * phi2))
		  );
}

/**
 Second momentum.

 \f[ \dot p_2 = \ldots \f]
 */
double dotp2(double x, double *y, double *a) {
	double phi1 = y[0];
	double phi2 = y[1];
	double omega1 = y[2];
	double omega2 = y[3];

	double g = a[0];
	double m = a[1];
	double L = a[2];

	return (
			2.*sin(phi1-phi2) * (omega1*omega1 * L * (m + m) + g*(m+m) * cos(phi1) + omega2*omega2 * L * m * cos(phi1-phi2))
		   )
		/
		(L*(2. * m + m - m* cos(2.*phi1-2.*phi2))
		);
}

/**
 Hamiltonian of the system.

 \f[ H = \ldots \f]
 */
double hamiltonian(double *y, double *a) {
	double phi1 = y[0];
	double phi2 = y[1];
	double omega1 = y[2];
	double omega2 = y[3];

	double g = a[0];
	double m = a[1];
	double L = a[2];

	return 1./6. * m * L*L * (
			omega2*omega2 + 4.*omega1*omega1 + 3. * omega1*omega2 * cos(phi1-phi2)
			)
		- .5 * m * g * L * (3. * cos(phi1) + cos(phi2));
}

void problem3_runge_kutta() {
	puts("problem3_runge_kutta()");
	double h = .001;
	double x = 0.;
	double y[] = {0., .2, 0., 0.};
	ode f[] = {dotphi1, dotphi2, dotp1, dotp2};
	int n = 4;
	struct state ccs;
	rk4_init_state(n, &ccs);
	FILE *fp = fopen("out/3-rk.txt", "w");
	assert(fp);
	while (x <= 5) {
		fprintf(fp, "%15g %15g %15g %15g %15g %15g\n", x, y[0], y[1], y[2],
				y[3], hamiltonian(y, aufgabe3_a));
		rk4(n, h, &x, y, f, aufgabe3_a, &ccs);
	}
	fclose(fp);
}

void problem3_cash_carp() {
	puts("problem3_cash_carp()");
	double h = .001;
	double x = 0.;
	double y[] = {0., .2, 0., 0.};
	ode f[] = {dotphi1, dotphi2, dotp1, dotp2};
	int n = 4;
	struct cash_carp_state ccs;
	cash_carp_init_state(n, &ccs);
	FILE *fp = fopen("out/3-cc.txt", "w");
	assert(fp);
	while (x <= 5) {
		fprintf(fp, "%15g %15g %15g %15g %15g %15g\n", x, y[0], y[1], y[2],
				y[3], hamiltonian(y, aufgabe3_a));
		cash_carp(n, h, &x, y, f, aufgabe3_a, &ccs);
	}
	fclose(fp);
}

void problem3() {
	double g = 9.81;
	double m = .1;
	double L = .4;

 	aufgabe3_a[0] = g;
	aufgabe3_a[1] = m;
	aufgabe3_a[2] = L;

	printf("Using a[0] = %3g, a[1] = %3g\n", aufgabe3_a[0], aufgabe3_a[1]);

	problem3_runge_kutta();
	problem3_cash_carp();
}
