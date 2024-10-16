#include <print>
#include <fstream>
#include <string>
#include <exception>
#include <iostream>

using namespace std;

void funcOne();
void funcTwo();

int main()
{
	try {
		funcOne();
	} catch (const exception& /* e */) {
		println(cerr, "Exception caught!");
		return 1;
	}
}

void funcOne()
{
	string str1;
	string* str2{ new string{} };
	funcTwo();
	delete str2;
}

void funcTwo()
{
	ifstream fileStream;
	fileStream.open("filename");
	throw exception {};
	fileStream.close();
}
