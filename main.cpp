// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

#include <iostream>

#include "bisect.hpp"

/**
 @mainpage physik441 problem set 2
 @author Martin Ueding <dev@martin-ueding.de>
 @author Jan Weber

 @section compile Kompilieren und Ausführen

 Mit <tt>make dep && make</tt> wird alles kombiliert und ausgeführt, die
 Ausgaben erscheinen ganz unten in der Ausgabe von <tt>make</tt>:

     Ausgabe Programm
     ./main
     Roots -12
     U_d = 5.95465
     I_d = 1

 @section Abhängigkeiten

 - g++
 - make

 @section Überlegungen zu Aufgabe 2

 Der Strom, der durch die Diode geht ist:

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
 Test function.

 It has roots at x=-1 and x=2.
 */
double parabola(double x) {
	return x * x - x - 2;
}

double i_d(double u_d) {
	double i_s = 1.0e-10;
	double m = 1.5;
	double u_t = 259.0e-3;

	return i_s * exp(u_d / (m * u_t));
}

double f(double u_d) {
	double r = 100.0;
	double u0 = 6.0;

	return u0 - u_d - r * i_d(u_d);
}

int aufgabe_a() {
	double root1 = bisect::bisect(-5.0, 0.0, parabola, 10000, 1.0e-10);
	double root2 = bisect::bisect(0.0, 5.0, parabola, 10000, 1.0e-10);
	std::cout << "Roots " << root1 << root2 << "\n";
	return 0;
}

int aufgabe_b() {
	double u_d = bisect::bisect(0.0, 100.0, f, 1000000, 1e-6);
	double i_d_ = i_d(u_d);
	std::cout << "U_d = " << u_d << std::endl;
	std::cout << "I_d = " << i_d << std::endl;

	return 0;
}

int main(int argc, char **argv) {
	aufgabe_a();
	aufgabe_b();
}
