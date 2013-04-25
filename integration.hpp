// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef INTEGRATION_H
#define INTEGRATION_H

namespace nume {
	double integrate_simpson(double (*f)(double), double lower, double upper, double sections);
}

#endif /* end of include guard: INTEGRATION_H */
