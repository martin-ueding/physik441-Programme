// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#ifndef P1_H
#define P1_H

#include <math.h>
#include <stdio.h>

double f1(double x);
double f2(double x);

double integrate_simpson(double (*f)(double), double lower, double upper, int section_count);

void problem1();

#endif /* end of include guard: P1_H */
