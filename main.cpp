// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

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

 Wenn zwei Sammler zusammen arbeiten, werden pro Person weniger Alben
 gebraucht.

 \image html out-2b.png

 \subsubsection aufgabe2c Aufgabe 2c

 Da nur einige der Karten halb so oft vorkommen sollen, wird wenn so eine Karte
 mit einem deutschen Spieler gezogen worde ist, mit einer Wahrscheinlichkeit
 von 0,5 erneut gezogen.

 \image html out-2c.png
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
	int max_iter = 1000000;
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
	std::cout << "\nAufgabe 2a" << std::endl;

	unsigned int max_iter = 1000000;

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
	std::cout << "\nAufgabe 2b" << std::endl;
	unsigned int max_iter = 1000000;

	std::ofstream out;
	out.open("out-2b.csv");

	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::Album mine(535), other(535);

		int steps = 0;

		while (!mine.is_full() && !other.is_full()) {
			steps++;

			std::vector<unsigned int> pack = mine.generate_pack();
			for (unsigned int &card: pack) {

				if (!mine.has_card(card)) {
					mine.add_card(card);
				}
				else {
					other.add_card(card);
				}
			}

			pack = other.generate_pack();
			for (unsigned int &card: pack) {

				if (!other.has_card(card)) {
					other.add_card(card);
				}
				else {
					mine.add_card(card);
				}
			}
		}

		out << steps << std::endl;
	}
	out.close();

	std::cout << "Siehe Plot" << std::endl;
}

void aufgabe2c() {
	std::cout << "\nAufgabe 2c" << std::endl;
	unsigned int max_iter = 1000000;

	std::ofstream out;
	out.open("out-2c.csv");
	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::AlbumSkewed album(535);
		unsigned int steps = album.fill_up();
		out << steps << std::endl;
	}
	out.close();

	std::cout << "Siehe Plot" << std::endl;
}

int main() {
	aufgabe1();
	aufgabe2a();
	aufgabe2b();
	aufgabe2c();

	return 0;
}
