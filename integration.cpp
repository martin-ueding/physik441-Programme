// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "integration.hpp"

double nume::integrate_simpson(double (*f)(double), double lower, double upper, double section_count) {
	double result = 0.;

	double section_width = (upper-lower)/section_count;

	for (int section_id = 0; section_id < section_count; ++section_id) {
		double x = lower + section_width * section_id;
		if (section_id == 0 || section_id == section_count) {
			result += f(x);
		}
		else if (section_id % 2 != 0) {
			result += 4 * f(x);
		}
		else {
			result += 2 * f(x);
		}
	}

	result *= section_width/3;

	return result;
}
