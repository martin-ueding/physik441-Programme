// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef BISECTTEST_H
#define BISECTTEST_H

#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestSuite.h>

#include "bisect.hpp"

class BisectTest: public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BisectTest);
	CPPUNIT_TEST(testOppositeSigns);
	CPPUNIT_TEST_SUITE_END();

	public:
		void testOppositeSigns();
};

#endif /* end of include guard: BISECTTEST_H */
