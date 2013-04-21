// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef BISECTTEST_H
#define BISECTTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "bisect.hpp"

/**
 Tests for the bisect namespace.
 */
class BisectTest: public CppUnit::TestFixture {
		CPPUNIT_TEST_SUITE(BisectTest);
		CPPUNIT_TEST_EXCEPTION(testException, bisect::NoRootException);
		CPPUNIT_TEST(testOppositeSigns);
		CPPUNIT_TEST_SUITE_END();

	public:
		/**
		 Tests the oppsoite_signs function.
		 */
		void testOppositeSigns();

		/**
		 Checks for the exception.
		 */
		void testException();

	private:
		/**
		 Test function that always gives one.

		 @param[in] x Input value.
		 @returns Always 1.0.
		 */
		static double one(double x);
};

#endif /* end of include guard: BISECTTEST_H */
