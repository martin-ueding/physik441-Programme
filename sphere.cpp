// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "sphere.hpp"

void nume::sphere_draw(struct random_data &buf, ublas::vector<double> &result) {
	for (ublas::vector<double>::iterator x = result.begin(); x != result.end(); x++) {
		int r;
		random_r(&buf, &r);
		*x = r;
		std::cout << *x << std::endl;
	}
}

void nume::test_sphere_draw() {
	struct random_data buf;

	int steps = 10;

	std::vector< ublas::vector<double> > data(steps);

	for (std::vector< ublas::vector<double> >::iterator row = data.begin();
			row != data.end(); row++) {
		*row = ublas::vector<double>(3);
		nume::sphere_draw(buf, *row);
	}

	std::ofstream out;
	out.open("out-3a.txt");
	for (std::vector< ublas::vector<double> >::iterator row = data.begin();
			row != data.end(); row++) {
		for (ublas::vector<double>::iterator coordinate = row->begin(); coordinate != row->end(); coordinate++) {
			out << *coordinate << " ";
		}
		out << "\n";
	}
	out.close();
}
