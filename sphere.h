// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#ifndef SPHERE_H
#define SPHERE_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Transforms the data.
 */
void hammer_aitov(double *input, double *output);

/**
 * Draws a point on the unit sphere.
 */
void sphere_draw(double *x, double *y, double *z);

void test_sphere_draw();

#endif /* end of include guard: SPHERE_H */
