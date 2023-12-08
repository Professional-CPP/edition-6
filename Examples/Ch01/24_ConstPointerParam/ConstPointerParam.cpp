import std;

using namespace std;

void mysteryFunction(const string* someString)
{
	*someString = "Test";  // Will not compile.
}

int main()
{
	string myString{ "The string" };
	mysteryFunction(&myString);  // &myString is a string*
}
