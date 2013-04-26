// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file
 \mainpage physik441 – Übung 3
 \author Martin Ueding <dev@martin-ueding.de>
 \author Jan Weber

 \section kompilieren Kompilieren und Ausführen

 Wie immer, mit <tt>make dep && make -j4</tt> werden alle Programmteile
 kompiliert und ausgeführt. Mit <tt>make dep && make -j4 test</tt> können die
 Tests ausgeführt werden.

 \subsection abhängigkeiten Abhängigkeiten

 - g++
 - Boost (uBLAS)
 - Python 2
 - \c python-matplolib
 - CppUnit (allerdings nur für <tt>make test</tt>)

 \section aufgaben Aufgaben

 \subsection aufgabe1 Aufgabe 1

 Die Fixpunkte \f$ f(x) = x \f$ (intern f1()) liegen bei \f$ x = -3.23293 \f$
 und \f$ x = 7.73293 \f$. Dies haben wir mit Mathematica bestimmt:

     Solve[0.2 x^2 + 0.1 x - 5 == x, x]
     {{x -> -3.23293}, {x -> 7.73293}}

 Das Programm liefert für den Startwert 0 ab einem gewissen Iterationsindex die
 Werte -5 und 0.5 im Wechsel. Nach 30 Iterationen ist meist 0.5 erreicht.

 \image html out-1.png

 \subsection aufgabe2 Aufgabe 2

 In Aufgabe 2 liefert das Newton-Rhapson Verfahren als Fixpunkt:
 \f[
	\vec x = (0.423854 \quad 0.423854)^T
 \f]

 Dies ist definitiv eine Nullstelle der Funktion, wie wir mit Mathematica erhalten haben:

     f[x1, x2] := {x1^3 + x2 - .5, x1^2 - x2^2}

     Solve[f[x1, x2] == {0, 0}, {x1, x2}]
     {{x1 -> -0.595744 - 0.254426 I,
      x2 -> 0.595744 + 0.254426 I}, {x1 -> -0.595744 + 0.254426 I,
      x2 -> 0.595744 - 0.254426 I}, {x1 -> -0.211927 - 1.06524 I,
      x2 -> -0.211927 - 1.06524 I}, {x1 -> -0.211927 + 1.06524 I,
      x2 -> -0.211927 + 1.06524 I}, {x1 -> 0.423854,
      x2 -> 0.423854}, {x1 -> 1.19149, x2 -> -1.19149}}

 Die Funktion nume::newton_rhapson() ist so gebaut, dass sie eine beliebige
 Funktion und zugehörige inverse Jakobimatrix benutzen kann.

 \subsection aufgabe4 Aufgabe 4

 Das zu bestimmende Integral ist:
 \f[
	\int_{-2}^1 \mathrm dx \, \left( x^3 + 2 x^2 + \frac 12 x + 2 \right) = 7.5
 \f]

 Nach 1000 Durchläufen ist das Ergebnis von 7.49451 erreicht.

 Im Plot ist der Fehler zu sehen. Interessanterweise gibt es bei bestimmten
 Durchlaufzahlen keinen Fehler sondern ein exaktes Ergebnis. Diese habe ich in
 einer anderen Farbe geplottet:

 \image html out-4.png

 Daran fittet das \c plot Programm die Funktion, wobei die ersten 50
 Datenpunkte ausgelassen werden:
 \f[
     f(n) = c n^e
 \f]

 Mit Fitparametern erhalten wir:
 \f[
     5.18894594057 n^{-0.991231680783}
 \f]

 Somit ist die Abhängigkeit wohl \f$ n^{-1} \f$.

 \subsection aufgabe5 Aufgabe 5

 \image html out-5.png
 */

#include <iostream>

#include "aufgaben.hpp"

int main() {
	aufgabe1();
	aufgabe2();
	aufgabe4();
	aufgabe5();

	return 0;
}
