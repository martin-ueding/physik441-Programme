// Copyright © 2013 Martin Ueding <cdev@martin-ueding.de>

/**
 \mainpage physik441-05

 \tableofcontents

 \include output.txt

 \section aufgaben Aufgaben

 \subsection aufgabe3 Aufgabe 3

 \subsubsection aufgabe3a Aufgabe 3a

 \image html out-3a-data.png

 \image html out-3a-transformed.png
 */

#include <stdio.h>
#include <stdlib.h>

#include "3.h"
#include "sphere.h"

int main(int argc, char **argv) {
	test_sphere_draw();
	problem3b();

	return 0;
}
