// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#ifndef AUFGABEN_H
#define AUFGABEN_H

#include <iostream>

#include "bisect.hpp"

/**
 Test function.

 It has roots at x=-1 and x=2.

 @param[in] x x value.
 */
double parabola(double x);

double i_d(double u_d);

double f(double u_d);

int aufgabe_a();

int aufgabe_b();

#endif /* end of include guard: AUFGABEN_H */
