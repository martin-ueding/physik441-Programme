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
#include <mutex>
#include <thread>
#include <vector>

#include "panini.hpp"

std::mutex mutex;

void concurrent_print(std::string s) {
	mutex.lock();
	std::cout << s << std::endl;
	mutex.unlock();
}

void aufgabe1() {
	concurrent_print("Aufgabe 1 start");

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

	concurrent_print("Aufgabe 1 fertig");
}

void aufgabe2a() {
	concurrent_print("Aufgabe 2a start");

	unsigned int max_iter = 1000000;

	std::ofstream out;
	out.open("out-2a.csv");
	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::Album album(535);
		unsigned int steps = album.fill_up();
		out << steps << std::endl;
	}
	out.close();

	concurrent_print("Aufgabe 1a fertig");
}

void aufgabe2b() {
	concurrent_print("Aufgabe 2b start");
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

	concurrent_print("Aufgabe 2b fertig");
}

void aufgabe2c() {
	concurrent_print("Aufgabe 2c start");
	unsigned int max_iter = 1000000;

	std::ofstream out;
	out.open("out-2c.csv");
	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::AlbumSkewed album(535);
		unsigned int steps = album.fill_up();
		out << steps << std::endl;
	}
	out.close();
	concurrent_print("Aufgabe 2c fertig");
}

int main() {
	std::thread t1(aufgabe1);
	std::thread t2(aufgabe2a);
	std::thread t3(aufgabe2b);
	std::thread t4(aufgabe2c);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}
