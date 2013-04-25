// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef INTEGRATION_H
#define INTEGRATION_H

namespace nume {
	/**
	 Integrates using the Simpson algorithmn.

	 @param[in] f Real function to integrate
	 @param[in] lower Lower bound @f$ a @f$
	 @param[in] upper Upper bound @f$ b @f$
	 @param[in] section_count Number of sections
	 @returns Integral @f$ \int_a^b \mathrm dx \, f(x) @f$
	 */
	double integrate_simpson(double(*f)(double), double lower, double upper, double section_count);
}

#endif /* end of include guard: INTEGRATION_H */
