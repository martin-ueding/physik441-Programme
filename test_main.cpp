// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include <cppunit/TextTestRunner.h>

#include "test_BisectTest.hpp"

int main() {
	CppUnit::TextTestRunner runner;
	runner.addTest(BisectTest::suite());
	runner.run();
	return 0;
}
