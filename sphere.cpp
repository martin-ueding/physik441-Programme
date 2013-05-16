// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "sphere.hpp"

void nume::sphere_draw(boost::function<double()> &dice, ublas::vector<double> &result) {
	for (double &x: result) {
		x = dice();
		//std::cout << x << std::endl;
	}
}

void nume::test_sphere_draw() {
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 2 * std::atan(1) * 4);
	std::function<double()> dice = std::bind(distribution, generator);

	int steps = 10;

	std::vector<ublas::vector<double>> data(steps);

	for (iterator it = data.begin(); begin != data.end(); it++) {
		*it = ublas::vector<double>(3);
		nume::sphere_draw(dice, *it);
	}

	std::ofstream out;
	out.open("out-3a.txt");
	for (iterator it = data.begin(); begin != data.end(); it++) {
		for (double &coordinate: row) {
			out << coordinate << " ";
		}
		out << "\n";
	}
	out.close();
}
