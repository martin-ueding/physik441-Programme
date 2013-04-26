// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef TEST_INTEGRATION_H
#define TEST_INTEGRATION_H

#include <cppunit/extensions/HelperMacros.h>

#include "integration.hpp"

class IntegrationTest: public CppUnit::TestFixture {
		CPPUNIT_TEST_SUITE(IntegrationTest);
		CPPUNIT_TEST(test_simpson);
		CPPUNIT_TEST_SUITE_END();

	public:
		void test_simpson();

	private:
		/**
		 \returns \f$ \frac 12 x^2 \f$
		 */
		static double parabola(double x);
};


#endif /* end of include guard: TEST_INTEGRATION_H */
