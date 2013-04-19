// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

/**
 @file
 Container for the individual problems.
 */

#ifndef AUFGABEN_H
#define AUFGABEN_H

#include <iostream>

#include "bisect.hpp"

/**
 Test function.

 The function: @f$ x \mapsto x^2 - x - 2 @f$. It has roots at x=-1 and x=2.

 @param[in] x x value.
 */
double parabola(double x);

/**
 Gives the output current for a given voltage through the diode.

 @param[in] u_d Input voltage.
 @returns Current through the diode.
 */
double i_d(double u_d);

/**
 Function for problem b.

 It has a root at the <tt>u_d</tt> of interest.

 @param[in] u_d Voltage on the diode.
 */
double f(double u_d);

/**
 Implementation of problem a.
 */
void aufgabe_a();

/**
 Implementation of problem b.
 */
void aufgabe_b();

#endif /* end of include guard: AUFGABEN_H */
