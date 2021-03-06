// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

/**
 @mainpage physik441 problem set 2
 @author Martin Ueding <dev@martin-ueding.de>
 @author Jan Weber
 @copyright GNU Public License 2 (oder neuer)

 Zu dieser Aufgabe existiert ein git Repository auf
 https://github.com/martin-ueding/physik441-02.

 Diese Dokumentation ist auch auf http://martin-ueding.de/apidoc/physik441-02/
 zu finden.

 @section kompilieren Kompilieren und Ausführen

 Mit <tt>make dep && make -j4</tt> wird alles kombiliert und ausgeführt, die
 Ausgaben erscheinen ganz unten in der Ausgabe von <tt>make</tt>:

     Ausgabe Programm
     ./main
     Roots -1, 2
     U_d = 5.95465
     I_d = 1

 Mit den Korrekturen für den Übungszettel gibt das Programm aus:

	 Ausgabe Programm
	 ./main
	 Roots -1, 2
	 U_d = 0.779844
	 I_d = 1

 Mit <tt>make test</tt> können die Unittests ausgeführt werden.

 @section Abhängigkeiten

 - g++
 - make

 Die Dokumentation kann mit <tt>make doc</tt> generiert werden, wenn
 <tt>doxygen</tt> installiert ist.

 @section überlegungen Überlegungen zu Aufgabe 2

 Der Strom, der durch die Diode geht, ist:

 @f[
     I_D(U_D) = I_S \exp\left( \frac{U_D}{m U_T} \right)
 @f]

 Die Spannung, die über dem Widerstand und der Diode abfällt, muss gerade die
 Eingangsspannung sein:

 @f[
     U_0 - U_D + R I_D (U_D) = 0
 @f]
 */

/**
 @file
 Main function.
 */

#include "aufgaben.hpp"

/**
 Main function of the program.
 */
int main(int argc, char **argv) {
	aufgabe_a();
	aufgabe_b();
}
