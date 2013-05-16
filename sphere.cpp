// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "sphere.hpp"

void nume::sphere_draw(std::function<double()> dice, ublas::vector<double> &result) {

}

void nume::test_sphere_draw() {
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 2 * std::atan(1) * 4);
	std::function<double()> dice = std::bind(distribution, generator);

	int steps = 10;

	std::vector<ublas::vector<double>> data(steps);

	for (ublas::vector<double> &row: data) {
		row = ublas::vector<double>(3);
		nume::sphere_draw(dice, row);
	}

	std::ofstream out;
	out.open("out-3a.txt");
	for (ublas::vector<double> row: data) {
		out << row << "\n";
	}
	out.close();
}
