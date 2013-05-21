// Copyright © 2013 Martin Ueding <cdev@martin-ueding.de>

/**
 \mainpage physik441-05
 \tableofcontents

 \author Martin Ueding <dev@martin-ueding.de>
 \author Jan Weber

 \section kompilieren Kompilieren und Ausführen

 Diese Abgabe ist in C 99 geschrieben und kann, wie immer, mit

	 make dep
     make
	 ./main
	 ./plot

 kompiliert, ausgeführt und geplottet werden.

 Ausgabe des Programms:

 \include output.txt

 \section aufgaben Aufgaben

 \subsection aufgabe1 Aufgabe 1

 \subsubsection aufgabe1a Aufgabe 1a

 Laut Mathematica sollte das Integral ergeben:

     Integrate[1/(1 + x^2)^(4/3), {x, 0, Infinity}] // N
	 1.12025
 
 \image html 1-f.png

 Das Programm rechnet:

 \include out-1a.txt

 Und erhält in der Tat mit vielen Schritten einen Wert, der nahe am
 analytischen Ergebnis liegt.

 \subsection aufgabe3 Aufgabe 3

 \subsubsection aufgabe3a Aufgabe 3a

 Die gezogenen Punkte, als \f$ z \f$-Projektion:

 \image html out-3a-data.png

 Die gleichen Punkte nach der Hammer-Aitov-Projektion:

 \image html out-3a-transformed.png

 \bug Das sollte eigentlich eine gleichmäßig dichte Ellipse werden.

 \subsubsection aufgabe3b Aufgabe 3b

 \image html out-3b.png
 */

#include <stdio.h>
#include <stdlib.h>

#include "1.h"
#include "2.h"
#include "3.h"
#include "sphere.h"

int main(int argc, char **argv) {
	//problem1();
	problem2();
	//test_sphere_draw();
	//problem3b();

	return 0;
}
