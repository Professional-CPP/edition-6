#pragma once
#include <CppUnitTest.h>

TEST_CLASS(FooTest)
{
public:
	TEST_METHOD(testConstructorALessThanB);
	TEST_METHOD(testConstructorABiggerThanB);
	TEST_METHOD(testConstructorAEqualB);
	TEST_METHOD(testGetA);
	TEST_METHOD(testGetB);
};
