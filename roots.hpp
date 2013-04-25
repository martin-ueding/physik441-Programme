// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef ROOTS_H
#define ROOTS_H

#include <iostream>

/**
 Stuff written in the physik441 “Numerische Methoden der Physik” course.
 */
namespace nume {
	/**
	 Finds fix points of the given function.

	 @param f Real function
	 @param[in] start Start value
	 @param[in] max_iter Maximal number of iterations
	 */
	double banach_fix(double(*f)(double), double start, int max_iter);
}

#endif /* end of include guard: ROOTS_H */
