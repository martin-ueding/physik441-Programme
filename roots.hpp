// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef ROOTS_H
#define ROOTS_H

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <iostream>

namespace ublas = boost::numeric::ublas;

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

	/**
	 Newton-Rhapson root finding algorithmn in multiple dimensions.

	 This functions uses the <tt>boost::numeric::ublas</tt> <tt>vector</tt> and
	 <tt>matrix</tt> classes to represent the mathematical structures.

	 The user has to give a function @f$ f: R^n \mapsto R^n @f$
	 and the inverse Jacobian @f$ 1/(\mathrm Df) @f$.

	 @param[in] f Input function
	 @param[in] inverse_jacobian A function, that gives the inverse jacobian at the given point.
	 @param[in] x Start value
	 @param[in] max_iter Number of iterations
	 @returns Position of root
	 */
	ublas::vector<double> newton_rhapson(
			std::function<ublas::vector<double>(ublas::vector<double>)> f,
			std::function<ublas::matrix<double>(ublas::vector<double>)>
			inverse_jacobian, ublas::vector<double> x, int max_iter);

}

#endif /* end of include guard: ROOTS_H */
