// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Licensed under The MIT License

/**
 \file
 */

#ifndef AUFGABE1_H
#define AUFGABE1_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aufgabe1();
int check_convergence(double *data, int size);
void gauss_seidel_step(double *data, int size, double *x);
void matrix_load(FILE *fp, int size, double *data);
void matrix_print(double *data, int size);
void matrix_save(char *filename, double *data, int size);
void maximize_diagonal(double *data, int size);
void print_line(double *data, int size);
double residual(double *data, int size, double *x);
void save_line(char* filename, double *data, int size);
void swap_lines(double *data, int size, int source, int target);
double trace(double *data, int size);

#endif /* end of include guard: AUFGABE1_H */
