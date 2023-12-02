#include "FooTest.h"

import foo;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FooTest::testConstructorALessThanB()
{
	// IF nothing

	// WHEN constructing a Foo with valid arguments
	Foo f{ 1,2 };

	// THEN no exception is thrown
}

void FooTest::testConstructorABiggerThanB()
{
	// IF nothing

	// WHEN constructing a Foo with a > b
	// THEN an invalid_argument exception is thrown.
	Assert::ExpectException<std::invalid_argument>(
		[] { Foo f{ 2, 1 }; });
}

void FooTest::testConstructorAEqualB()
{
	// IF nothing

	// WHEN constructing a Foo with a == b
	// THEN an invalid_argument exception is thrown.
	Assert::ExpectException<std::invalid_argument>(
		[] { Foo f{ 2, 2 }; });
}

void FooTest::testGetA()
{
	// IF a valid Foo is constructed
	const int originalA{ 11 };
	const int originalB{ 22 };
	Foo f{ originalA, originalB };

	// WHEN requesting the value of a
	auto a{ f.getA() };

	// THEN the returned value is as expected.
	Assert::AreEqual(originalA, a);
}

void FooTest::testGetB()
{
	// IF a valid Foo is constructed
	const int originalA{ 11 };
	const int originalB{ 22 };
	Foo f{ originalA, originalB };

	// WHEN requesting the value of b
	auto b{ f.getB() };

	// THEN the returned value is as expected.
	Assert::AreEqual(originalB, b);
}