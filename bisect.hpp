// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

/**
 @file
 The bisecting algorithmn.
 */

#ifndef BISECT_H
#define BISECT_H

#include <cmath>
#include <exception>
#include <iostream>

/**
 “Bisect” root finding algorithmn and helper functions.
 */
namespace bisect {
	/**
	 Finds a root of the given function.

	 See https://en.wikipedia.org/wiki/Bisection_method for an explanation of
	 this algorithmn.

	 @param a1 Minimal start value
	 @param a2 Maximal start value
	 @param f Function to use
	 @param max_iter Maximal number of iterations
	 @param precision Working precision
	 @throws NoRootException Thrown, if no root was found.
	 */
	double bisect(double a1, double a2, double(*f)(double), int max_iter, double precision);

	/**
	 Checks whether the arguments have opposite sign.

	 @param x1 First value.
	 @param x2 Second value.
	 */
	bool opposite_signs(double x1, double x2);

	/**
	 No root could be found for the given function and interval.
	 */
	class NoRootException: public std::exception {
		public:
			/**
			 Gives the error message.
			 */
			const char *what() {
				return "No root could be found.";
			}
	};
}

#endif /* end of include guard: BISECT_H */
