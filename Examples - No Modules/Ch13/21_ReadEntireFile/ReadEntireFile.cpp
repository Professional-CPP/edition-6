#include <print>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	ifstream inputFile{ "some_data.txt" };
	if (inputFile.fail()) {
		println(cerr, "Unable to open file for reading.");
		return 1;
	}
	string fileContents;
	getline(inputFile, fileContents, '\0');
	println("\"{}\"", fileContents);
}
