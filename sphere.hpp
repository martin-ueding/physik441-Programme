// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef SPHERE_H
#define SPHERE_H

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>

namespace ublas = boost::numeric::ublas;

namespace nume {
	/**
	  Maps the given 3D points onto a 2D map.

	  Then save this list of transformed points into outfilename.

	  \param[in] data 3D data
	  \param[in] outfilename Filename to write transformed data to
	  */
	void hammer_aitov_transformation(std::vector< ublas::vector<double> >
			&data, const std::string &outfilename);

	/**
	  Draws a point from the unit sphere.

	  \param[out] result Unit vector
	  */
	void sphere_draw(struct random_data &buf, ublas::vector<double> &result);

	void test_sphere_draw();
}

#endif /* end of include guard: SPHERE_H */
