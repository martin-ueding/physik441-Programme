// Copyright © 2013 Martin Ueding <cdev@martin-ueding.de>

/**
 \mainpage physik441-05
 \tableofcontents

 Abgabe für den 5. Zettel aus <a
 href="http://www.astro.uni-bonn.de/~jpflamm/nmp_ss13.html">Numerische Methoden
 der Physik (SS 2013)</a>.

 \author Martin Ueding <dev@martin-ueding.de>
 \author Jan Weber

 \section kompilieren Kompilieren und Ausführen

 Diese Abgabe ist in <em>C 99</em> geschrieben und kann, wie immer, mit

 \code
 make dep
 make
 ./main
 ./plot
 \endcode

 kompiliert, ausgeführt und geplottet werden.

 Dazu wird gebraucht:

 - gcc
 - python
 - python-matplotlib
 - python-numpy
 - python-scipy

 \subsection ausgabe Ausgabe

 Ausgabe des Programms:

 \include output.txt

 \section aufgaben Aufgaben

 \subsection aufgabe1 Aufgabe 1

 \subsubsection aufgabe1a Aufgabe 1a

 Laut Mathematica sollte das Integral ergeben:

 \code
 Integrate[1/(1 + x^2)^(4/3), {x, 0, Infinity}] // N
 1.12025
 \endcode
 
 \image html 1-f.png

 Das Programm rechnet:

 \include out-1a.txt

 Und erhält in der Tat mit vielen Schritten einen Wert, der nahe am
 analytischen Ergebnis liegt.

 \subsubsection aufgabe1b Aufgabe 1b

 \todo Dieser Aufgabenteil fehlt.

 \subsection aufgabe2 Aufgabe 2

 \subsubsection aufgabe2a Aufgabe 2a

 \image html out-2a.png

 \subsubsection aufgabe2b Aufgabe 2b

 Die Funktion habe ich eingehüllt mit:
 \f[
 e(x) =
 \begin{cases}
 0 & 0 \leq x \leq 2.0708 \\
 1.24248 - 0.3x & 2.0708 < x < 1 + \pi \\
 0 & \text{sonst}
 \end{cases}
 \f]

 \code
 e[x_] = Piecewise[{{.3 x, 0 <= x && x <= .5 + Pi/2}, {-.3 x + (Pi + 1)*.3, x >
     .5 + Pi/2 && x <= Pi + 1}}]
 \endcode

 Zusammen mit der Sinusverteilung sieht dies so aus:

 \code
 Plot[{.5 Sin[x - .5], e[x]}, {x, 0, Pi + 1}, PlotRange -> Full]
 \endcode

 \image html 2-einhuellende.png

 Nun integriere ich diese Funktion von \f$ 0 \f$ bis \f$ 1 + \pi \f$, um die
 Normierung zu erhalten. Dabei erhalte ich den Wert \f$ \alpha := 1.28646 \f$.
 Ich integriere die Funktion \f$ e(x)/\alpha \f$ ohne Grenzen nach \f$ x \f$
 und erhalte folgende CDF:
 \f[
 E(x) =
 \begin{cases}
 0 & x \leq 0 \\
 0.116599 x^2 & 0 \leq x \leq 2.0708 \\
 -1. - 0.233198 (-4.14159 x + 0.5 x^2) & 2.0708 < x \leq 4.14159 \\
 1 & \text{sonst}
 \end{cases}
 \f]

 An den Randwerten \f$ x = 0 \f$ und \f$ x = 1 + \pi \f$ nimmt die Funktion die
 erforderten Werte 0 und 1 an. Diese CDF ist hier geplottet:

 \image html 2-cdf.png

 Ich bestimme die Umkehrfunktion:
 \f[
 E^{-1}(z) =
 \begin{cases}
 2.92855 \sqrt z & 0 \leq z \leq 0.5 \\
 4.14159 - 2.92855 \sqrt{1 - z} & 0.5 < z \leq 1 \\
 \end{cases}
 \f]

 Wenn ich nun \f$ z \f$ gleichmäßig zwischen 0 und 1 ziehe, kann ich mit \f$
 E^{-1}(z) \f$ eine Zahl finden, die aus der Dreiecksverteilung gezogen worden
 ist.

 In dieser Abgabe ist diese Funktion als inverse_cdf() implementiert.

 Die Akzeptanzrate ist in \ref ausgabe. Das Histogram ist hier:

 \image html out-2b.png

 \subsubsection aufgabe2c Aufgabe 2c

 Die Laufzeiten sind oben in der \ref ausgabe.

 Mit der einhüllenden Funktion steigt die Akzeptanzrate, und obwohl das Ziehen
 aufwändiger ist, spart dies Zeit.

 \subsection aufgabe3 Aufgabe 3

 \subsubsection aufgabe3a Aufgabe 3a

 Die gezogenen Punkte, als \f$ z \f$-Projektion:

 \image html out-3a-z.png

 Die gezogenen Punkte, als \f$ y \f$-Projektion:

 \image html out-3a-y.png

 \image html out-3a-3D.png

 Die gleichen Punkte nach der Hammer-Aitov-Projektion:

 \image html out-3a-transformed.png

 \subsubsection aufgabe3b Aufgabe 3b

 \image html out-3b.png

 Die Schrittzahl für den wirklichen \f$ R_\text{rad} \f$ steht oben in der
 \ref ausgabe.
 */

#include <stdio.h>
#include <stdlib.h>

#include "1.h"
#include "2.h"
#include "3.h"
#include "sphere.h"

int main(int argc, char **argv) {
	problem1();
	problem2();
	test_sphere_draw();
	problem3b();

	return 0;
}
