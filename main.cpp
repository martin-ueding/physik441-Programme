// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 @file
 @mainpage physik441 – Übung 3
 @author Martin Ueding <dev@martin-ueding.de>
 @author Jan Weber

 @section kompilieren Kompilieren und Ausführen

 Wie immer, mit <tt>make dep && make -j4</tt> werden alle Programmteile
 kompiliert und ausgeführt. Mit <tt>make dep && make -j4 test</tt> können alle
 Tests ausgeführt werden, diese benötigen die CppUnit Bibliothek.

 @section aufgaben Aufgaben

 @subsection aufgabe1 Aufgabe 1

 Die Fixpunkte @f$ f(x) = x @f$ (intern f1) liegen bei @f$ x = -3.23293 @f$
 und @f$ x = 7.73293 @f$. Dies haben wir mit Mathematica bestimmt:

     Solve[0.2 x^2 + 0.1 x - 5 == x, x]
     {{x -> -3.23293}, {x -> 7.73293}}

 Das Programm liefert für den Startwert 0 ab einem gewissen Iterationsindex die
 Werte -5 und 0.5 im Wechsel. Nach 30 Iterationen ist meist 0.5 erreicht.

 @subsection aufgabe4 Aufgabe 4

 Das zu bestimmende Integral ist:
 @f[
	\int_{-2}^1 \mathrm dx \, \left( x^3 + 2 x^2 + \frac 12 x + 2 \right) = 7.5
 @f]
 */

#include <iostream>

#include "aufgaben.hpp"

int main() {
	aufgabe1();
	aufgabe4();
	aufgabe5();

	return 0;
}
