// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef NUMEROV_H
#define NUMEROV_H

double numerov_step(int n, double h, double *s, double *u, double *r);
void numerov(int step_count, double h, double *s, double *u, double *r);

#endif /* end of include guard: NUMEROV_H */
