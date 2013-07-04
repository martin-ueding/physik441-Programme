// Taken from
// https://www.gnu.org/software/gsl/manual/html_node/An-Example-Program.html

#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

#include "aufgabe2.h"

void aufgabe2() {
	puts("# Aufgabe 2");
	double x = 5.0;
	double y = gsl_sf_bessel_J0(x);
	printf("J0(%g) = %.18e\n", x, y);
}
