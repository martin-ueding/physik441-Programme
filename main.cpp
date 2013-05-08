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

 \todo Fehlt
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
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

		//std::cout << x << " " << y << std::endl;

		if (x*x + y*y <= 1) {
			++in_circle;
		}

		pi = 4. * in_circle / max_iter;

		out << n << " " << pi << "\n";
	}

	out.close();

	std::cout << "Aufgabe 1\nSiehe Plot" << std::endl;
}

std::mutex mutex;

void task(unsigned int max_iter, std::vector<unsigned int> *results, std::vector<unsigned int>::iterator start) {
	for (unsigned int n = 0; n < max_iter; ++n) {
		nume::Album album(535);
		unsigned int steps = album.fill_up();
		mutex.lock();
		results->insert(start, steps);
		mutex.unlock();
	}
}

void aufgabe2() {
	std::cout << "\nAufgabe 2\n";

	unsigned int max_iter = 10000;

	unsigned int thread_count = 2;

	std::vector<std::thread> threads(thread_count);
	std::vector<unsigned int> results(max_iter);

	int i = 0;
	for (std::thread &thread: threads) {
		std::vector<unsigned int>::iterator start = results.begin() + max_iter/thread_count * i;
		thread = std::thread(task, max_iter/thread_count, &results, start);
		i++;
	}


	for (std::thread &thread: threads) {
		thread.join();
	}

	std::cout << results.size() << std::endl;

	std::ofstream out;
	out.open("out-2a.csv");
	for (unsigned int count: results) {
		out << count << std::endl;
	}
	out.close();

	std::cout << "Siehe Plot" << std::endl;
}

int main() {
	aufgabe1();
	aufgabe2();

	return 0;
}
