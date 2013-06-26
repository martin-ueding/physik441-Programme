// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

double numerov_step(int n, double h, double *s, double *u, double *r) {
	return (
			(2. - 5.* h*h/6. * s[n]) * u[n]
			- (1. + h*h/12. *s[n-1]) * u[n-1]
			+ h*h / 12. * (r[n+1] + 10*r[n] + r[n-1])
		   ) / (1. + h*h/12. * s[n+1]);
}

void numerov(int step_count, double h, double *s, double *u, double *r) {
	for (int step_id = 1; step_id < step_count -1; step_id++) {
		u[step_id+1] = numerov_step(step_id, h, s, u, r);
	}
}
