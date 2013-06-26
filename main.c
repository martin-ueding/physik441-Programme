// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "rk4.h"

double dgl_y(double x, double *y, double *a) {
	//double y_ = y[0];
	double y_prime = y[2];
	//double w_alpha = y[1];
	//double w_alpha_prime = y[3];
	return y_prime;
}

double dgl_y_prime(double x, double *y, double *a) {
	double y_ = y[0];
	//double y_prime = y[2];
	double w_alpha = y[1];
	//double w_alpha_prime = y[3];
	return 2.* y_ /(1.+x)/(1.+x) * w_alpha;
}

double dgl_w_alpha(double x, double *y, double *a) {
	//double y_ = y[0];
	//double y_prime = y[2];
	//double w_alpha = y[1];
	double w_alpha_prime = y[3];
	return w_alpha_prime;
}

double dgl_w_alpha_prime(double x, double *y, double *a) {
	//double y_ = y[0];
	//double y_prime = y[2];
	//double w_alpha = y[1];
	//double w_alpha_prime = y[3];
	return 2. / (1.+x)/(1.+x);
}

void aufgabe1() {
	puts("aufgabe1");
	double h = .01;
	double x;
	double alpha = 5.;
	double y[] = {1., 0., alpha, 1.};
	ode f[] = {dgl_y, dgl_w_alpha, dgl_y_prime, dgl_w_alpha_prime};
	int n = 4;
	struct state s;
	rk4_init_state(n, &s);
	FILE *fp = fopen("out/1.txt", "w");
	assert(fp);
	for (int iter_id = 0; iter_id < 100; iter_id++) {
		y[0] = 1.;
		y[1] = 0.;
		y[2] = alpha;
		y[3] = 1.;
		x = 0.;

		while (x <= 1.) {
			fprintf(fp, "%15g %15g %15g %15g %15g\n", x, y[0], y[1], y[2], y[3]);
			rk4(n, h, &x, y, f, NULL, &s);
		}

		alpha -= (y[0] - .5) / y[1];
	}
	fclose(fp);
}

int main(int argc, char **argv) {
	aufgabe1();

	return 0;
}
