// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "test_BisectTest.hpp"

void BisectTest::testOppositeSigns() {
	CPPUNIT_ASSERT(bisect::opposite_signs(-1., 1.));
}
