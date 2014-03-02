// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe zusammen mit Jan Weber

/*
 @file
 Main file for testing.
 */

#include <cppunit/TextTestRunner.h>

#include "test_BisectTest.hpp"

/**
 Main function of the test runner.
 */
int main() {
	CppUnit::TextTestRunner runner;
	runner.addTest(BisectTest::suite());
	runner.run();
	return 0;
}
