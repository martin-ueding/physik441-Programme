// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \file
 \mainpage physik441 – Übung 3
 \author Martin Ueding <dev@martin-ueding.de>
 \author Jan Weber

 \tableofcontents

 Diese Dokumentation ist auch unter
 http://martin-ueding.de/apidoc/physik441-03/ zu finden. Das git Repository ist
 unter https://github.com/martin-ueding/physik441-03 zu finden.

 \section kompilieren Kompilieren und Ausführen

 Wie immer, mit <tt>make dep && make -j4</tt> werden alle Programmteile
 kompiliert und ausgeführt. Mit <tt>make dep && make -j4 test</tt> können die
 Tests ausgeführt werden. Wegen Boost lohnt sich \c -j4 oder \c -j2 enorm.

 \subsection abhängigkeiten Abhängigkeiten

 - g++
 - Boost (uBLAS)
 - Python 2
 - \c python-matplolib
 - CppUnit (allerdings nur für <tt>make test</tt>)

 \subsection ausgabe Ausgabe

 \include output.txt

 \section aufgaben Aufgaben

 \subsection aufgabe1 Aufgabe 1

 Die Fixpunkte der Funktion f1() liegen bei \f$ x = -3.23293 \f$ und \f$ x =
 7.73293 \f$. Dies haben wir mit Mathematica bestimmt:

     Solve[0.2 x^2 + 0.1 x - 5 == x, x]
     {{x -> -3.23293}, {x -> 7.73293}}

 Das Programm liefert für den Startwert 0 ab einem gewissen Iterationsindex die
 Werte −5 und 0.5 im Wechsel. Nach 30 Iterationen ist meist 0.5 erreicht.

 \image html out-1.png

 \todo Es fehlt die Fehlerabschätzung mit der in der Vorlesung angegebenen
 Formel.

 \subsection aufgabe2 Aufgabe 2

 In Aufgabe 2 liefert das Newton-Rhapson Verfahren für die Funktion f3() als
 Fixpunkt:
 \f[
	\vec x = \begin{pmatrix} 0.423854 \\ 0.423854 \end{pmatrix}
 \f]

 Dies ist definitiv eine Nullstelle der Funktion, wie wir mit Mathematica
 erhalten haben:

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

 \subsection aufgabe3 Aufgabe 3

 Es soll die Fläche der Parabel \f$ P \f$ hergeleitet werden:
 \f[
     P = \frac{x_3 - x_1}{6} \left( f(x_1) + 4 f(x_2) + f(x_3) \right)
 \f]

 Mit Mathematica ist schnell zu sehen, dass das Polynom korrekt ist:

     In:= l1[x_] := (x - x2) (x - x3)/((x1 - x2) (x1 - x3))
     In:= l2[x_] := (x - x1) (x - x3)/((x2 - x1) (x2 - x3))
     In:= l3[x_] := (x - x1) (x - x2)/((x3 - x1) (x3 - x2))
     In:= p[x_] := y1 l1[x] + y2 l2[x] + y3 l3[x]
     In:= x2 := x1 + h
     In:= x3 := x1 + 2 h
     In:= Integrate[p[x], {x, x1, x3}] // Factor
     Out= 1/3 h (y1 + 4 y2 + y3)

 Dabei ist \f$ x_3 - x_1 = 2h \f$.

 Nun die Herleitung per Hand: Dazu betrachte ich den ersten Summanden:
 \f{align*}{
	     f(x_1) L_1(x)
			 &= f(x_1) \frac{(x-x_2)(x-x_3)}{(x_1-x_2)(x_1-x_3)} \\
	     \int_{x_1}^{x_3} \mathrm dx \, f(x_1) L_1(x)
			 &= \int_{x_1}^{x_3} \mathrm dx \, f(x_1) \frac{(x-x_2)(x-x_3)}{(x_1-x_2)(x_1-x_3)} \\
			 &= \frac{1}{2h^2} f(x_1) \int_{x_1}^{x_3} \mathrm dx \, (x-x_2)(x-x_3) \\
 \f}
 Darauf wende ich partielle Integration an:
 \f{align*}{
			 &= \frac{1}{2h^2} f(x_1) \left( \left. \frac 12(x-x_2)(x-x_3) \right|_{x_1}^{x_3} - \frac12 \int_{x_1}^{x_3} \mathrm dx \, (x-x_3)^2 \right) \\
			 &= \frac{1}{2h^2} f(x_1) \left( 2 h^3 - \frac16 \left. (x-x_3)^2 \right|_{x_1}^{x_3} \right) \\
			 &= \frac{1}{2h^2} f(x_1) \left( 2 h^3 - \frac 86 h^3 \right) \\
			 &= \frac 13 h f(x_1)
 \f}

 So ähnlich gehe ich für den zweiten Summanden vor. Dort erhalte ich:
 \f[
	 \int_{x_1}^{x_3} \mathrm dx \, f(x_2) L_2(x) = \frac 43 h f(x_2)
 \f]

 Und für den letzten Summanden wie beim Ersten auch:
 \f[
	 \int_{x_1}^{x_3} \mathrm dx \, f(x_3) L_3(x) = \frac 13 h f(x_3)
 \f]

 Alles zusammen also:
 \f[
	\frac 13 h \left( f(x_1) + 4 f(x_2) + f(x_3) \right)
	= 
	\frac{x_3 - x_1}6 \left( f(x_1) + 4 f(x_2) + f(x_3) \right)
 \f]

 \subsection aufgabe4 Aufgabe 4

 Das zu bestimmende Integral ist das Integral der Funktion f2():
 \f[
	\int_{-2}^1 \mathrm dx \, \left( x^3 + 2 x^2 + \frac 12 x + 2 \right) = 7.5
 \f]

 Nach 1000 Durchläufen ist das Ergebnis von 7.49451 erreicht.

 Im Plot ist der Fehler zu sehen. Interessanterweise gibt es bei bestimmten
 Durchlaufzahlen keinen Fehler sondern ein exaktes Ergebnis. Diese habe ich in
 beim Fitten weggelassen:

 \image html out-4.png

 Daran fittet das \c plot Programm die Funktion, wobei die ersten 50
 Datenpunkte ausgelassen werden:
 \f[
     n \mapsto c n^e
 \f]

 Mit Fitparametern erhalten wir:
 \f[
     5.18894594057 n^{-0.991231680783}
 \f]

 Somit ist die Abhängigkeit wohl \f$ n^{-1} \f$.

 \subsection aufgabe5 Aufgabe 5

 Die zu erwartende Periode bei einer reinen harmonischen Oszillation ist:
 \f[
	T = \frac{2\pi}{\omega} = 2 \pi \sqrt{\frac lg}
 \f]

 Hier der Plot des Abstandes der Funktion t() zur obigen Periode \f$ T \f$:

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
