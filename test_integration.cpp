// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "test_integration.hpp"

double IntegrationTest::parabola(double x) {
	return 3. * x * x;
}

void IntegrationTest::test_simpson() {
	double result = nume::integrate_simpson(parabola, 0., 1., 10);
	CPPUNIT_ASSERT(0.95 < result);
	CPPUNIT_ASSERT(result < 1.05);
}
