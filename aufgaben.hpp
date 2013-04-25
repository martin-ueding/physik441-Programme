// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 @file
 Functions for each problem.
 */

#ifndef AUFGABEN_H
#define AUFGABEN_H

#include <iostream>

#include "integration.hpp"
#include "roots.hpp"

/**
 Problem 1.
 */
void aufgabe1();

/**
 Problem 2.
 */
void aufgabe2();

/**
 Problem 3.
 */
void aufgabe3();

/**
 Problem 4.
 */
void aufgabe4();

/**
 Problem 5.
 */
void aufgabe5();

/**
 @returns @f$ 0.2x^2 + 0.1 x - 5 @f$
 */
double f1(double x);

/**
 @returns @f$ x^3 + 2x^2 + \frac 12 x + 2 @f$
 */
double f2(double x);

/**
 @returns @f$ \frac 12 x^2 @f$
 */
double parabola(double x);

/**
 Period of a physical pendulum.

 The period is calculated with the given formula:
 @f[
	T(k^2, l, g) = 4 \sqrt{\frac lg} \int_0^{\pi/2}
	\frac{\mathrm d\phi}{\sqrt{1-k^2 \sin^2(\phi)}}
 @f]

 And @f$ k @f$ is given by:
 @f[
	k^2 = \sin^2\left(\frac{\phi_0}2\right)
 @f]

 @param[in] k2 Value of k, already squared
 @param[in] l Length of the pendulum
 @param[in] g Gravitational acceleration
 @returns @f$ T(k^2, l, g) @f$
 */
double t(double k2, double l, double g);

#endif /* end of include guard: AUFGABEN_H */
