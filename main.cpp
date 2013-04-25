// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 @file
 @mainpage physik441 – Übung 3
 @author Martin Ueding <dev@martin-ueding.de>
 @author Jan Weber

 @section aufgaben Aufgaben
 @subsection aufgabe1 Aufgabe 1

 Die Fixpunkte @f$ f(x) = x @f$ (intern f1) liegen bei @f$ x = -3.23293 @f$ und @f$ x = -3.23293 @f$. Dies haben wir mit Mathematica bestimmt:

     Solve[0.2 x^2 + 0.1 x - 5 == x, x]
     {{x -> -3.23293}, {x -> 7.73293}}
 */

#include <iostream>

#include "aufgaben.hpp"

int main() {
	aufgabe1();

	return 0;
}
