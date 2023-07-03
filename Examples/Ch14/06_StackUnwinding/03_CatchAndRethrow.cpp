import std;

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
	try {
		funcTwo();
	} catch (...) {
		delete str2;
		throw; // Rethrow the exception.
	}
	delete str2;
}

void funcTwo()
{
	ifstream fileStream;
	fileStream.open("filename");
	throw exception {};
	fileStream.close();
}
