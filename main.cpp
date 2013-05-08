// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

/**
 \mainpage physik441-04

 \tableofcontents

 \section comile Komilieren und Ausführen

 Das Programm kann mit <tt>make dep && make</tt> kompiliert und mit \c ./main
 ausgeführt werden. Die Ausgabe ist:

 \include output.txt

 \section aufgaben Aufgaben

 \subsection aufgabe1 Aufgabe 1

 \image html out-1.png

 Vom Plot lese ich ab: Damit sich der Fehler um drei Zehnerpotenzen reduziert,
 muss die Iterationszahl um 5 Größenordnungen erhöhen. Die Abhängigkeit von \f$
 n \f$ ist dann in der Ecke von \f$ n^{-3/5} \f$.

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

const unsigned int max_iter = 100000;

void aufgabe1() {
	concurrent_print("Aufgabe 1 start");

	double max = 1.;
	double min = -1.;
	double pi;
	double x;
	double y;
	unsigned int n = 0;

	unsigned int in_circle = 0;

	std::srand(std::time(NULL));

	std::ofstream out;
	out.open("out-1.csv");

	for (n = 0; n < max_iter / 10; ++n) {
		x = ((double) std::rand() / (RAND_MAX)) * (max - min) + min;
		y = ((double) std::rand() / (RAND_MAX)) * (max - min) + min;

		if (x *x + y *y <= 1) {
			++in_circle;
		}

		pi = 4. * in_circle / n;

		out << n << " " << pi << "\n";
	}

	out.close();

	concurrent_print("Aufgabe 1 fertig");
}

void aufgabe2a() {
	concurrent_print("Aufgabe 2a start");

	int bin_count = 2000;
	std::vector<int> bins(bin_count, 0);

	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::Album album(535);
		int steps = album.fill_up();
		if (steps < bin_count) {
			bins[steps]++;
		}
	}

	std::ofstream out;
	out.open("out-2a.csv");
	for (int i = 0; i < bin_count; ++i) {
		if (bins[i] != 0) {
			out << i << " " << bins[i] << std::endl;
		}
	}
	out.close();

	concurrent_print("Aufgabe 1a fertig");
}

void aufgabe2b() {
	concurrent_print("Aufgabe 2b start");

	int bin_count = 2000;
	std::vector<int> bins(bin_count, 0);

	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::Album mine(535), other(535);

		int steps = 0;

		while (!mine.is_full() && !other.is_full()) {
			steps++;

			std::vector<unsigned int> pack = mine.generate_pack();
for (unsigned int & card: pack) {

				if (!mine.has_card(card)) {
					mine.add_card(card);
				}
				else {
					other.add_card(card);
				}
			}

			pack = other.generate_pack();
for (unsigned int & card: pack) {

				if (!other.has_card(card)) {
					other.add_card(card);
				}
				else {
					mine.add_card(card);
				}
			}
		}

		if (steps < bin_count) {
			bins[steps]++;
		}
	}

	std::ofstream out;
	out.open("out-2b.csv");
	for (int i = 0; i < bin_count; ++i) {
		if (bins[i] != 0) {
			out << i << " " << bins[i] << std::endl;
		}
	}
	out.close();

	concurrent_print("Aufgabe 2b fertig");
}

void aufgabe2c() {
	concurrent_print("Aufgabe 2c start");

	int bin_count = 2000;
	std::vector<int> bins(bin_count, 0);

	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::AlbumSkewed album(535);
		int steps = album.fill_up();
		if (steps < bin_count) {
			bins[steps]++;
		}
	}

	std::ofstream out;
	out.open("out-2c.csv");
	for (int i = 0; i < bin_count; ++i) {
		if (bins[i] != 0) {
			out << i << " " << bins[i] << std::endl;
		}
	}
	out.close();

	concurrent_print("Aufgabe 2c fertig");
}

void no_parallel() {
	aufgabe1();
	aufgabe2a();
	aufgabe2b();
	aufgabe2c();
}

void parallel() {
	std::thread t1(aufgabe1);
	std::thread t2(aufgabe2a);
	std::thread t3(aufgabe2b);
	std::thread t4(aufgabe2c);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

int main() {
	no_parallel();

	return 0;
}
