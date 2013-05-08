// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

/**
 \mainpage physik441-04

 \tableofcontents

 \section comile Komilieren und Ausführen

 Das Programm kann mit <tt>make dep && make</tt> kompiliert und ausgeführt
 werden. Die Ausgabe ist:

 \include output.txt

 \section aufgaben Aufgaben

 \subsection aufgabe1 Aufgabe 1

 \image html out-1.png

 Die Abhängigkeit ist anscheinend \f$ n^{-1} \f$.

 \subsection aufgabe2 Aufgabe 2

 \subsubsection aufgabe2a Aufgabe 2a

 In der Klasse nume::Album ist das Album implementiert. Es kann mit der Methode
 nume::Album::fill_up() solange Päckchen ziehen, bis dieses voll ist.
 Rückgabewert ist die Anzahl der Päckchen.

 \image html out-2a.png

 \subsubsection aufgabe2b Aufgabe 2b

 \image html out-2b.png

 \todo Fehlt
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

#include "panini.hpp"

void aufgabe1() {
	double max = 1.;
	double min = -1.;
	double pi;
	double x;
	double y;
	int max_iter = 10000;
	int n = 0;

	int in_circle = 0;

	std::srand(std::time(NULL));

	std::ofstream out;
	out.open("out-1.csv");

	for (n = 0; n < max_iter; ++n) {
		x = ((double) std::rand() / (RAND_MAX)) * (max-min) + min;
		y = ((double) std::rand() / (RAND_MAX)) * (max-min) + min;

		if (x*x + y*y <= 1) {
			++in_circle;
		}

		pi = 4. * in_circle / max_iter;

		out << n << " " << pi << "\n";
	}

	out.close();

	std::cout << "Aufgabe 1\nSiehe Plot" << std::endl;
}

void aufgabe2a() {
	std::cout << "\nAufgabe 2\n";

	unsigned int max_iter = 10000;

	std::ofstream out;
	out.open("out-2a.csv");
	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::Album album(535);
		unsigned int steps = album.fill_up();
		out << steps << std::endl;
	}
	out.close();

	std::cout << "Siehe Plot" << std::endl;
}

void aufgabe2b() {
}

int main() {
	aufgabe1();
	aufgabe2a();
	aufgabe2b();

	return 0;
}
