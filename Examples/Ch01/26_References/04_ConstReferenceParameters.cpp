import std;

using namespace std;

void printString(const string& myString)
{
	println("{}", myString);
}

int main()
{
	string someString{ "Hello World" };
	printString(someString);
	printString("Hello World");  // Passing literals works
}
