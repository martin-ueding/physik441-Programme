// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "test_BisectTest.hpp"

double BisectTest::one(double x) {
	return 1;
}

void BisectTest::testException() {
	CPPUNIT_ASSERT(bisect::bisect(-1., 1., BisectTest::one, 5, 0.1));
}

void BisectTest::testOppositeSigns() {
	CPPUNIT_ASSERT(bisect::opposite_signs(-1., 1.));
}
