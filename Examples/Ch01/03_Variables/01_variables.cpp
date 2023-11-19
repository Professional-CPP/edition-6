// NOTE: Most compilers will issue a warning or an error
// when code is using uninitialized variables. Some compilers
// will generate code that will report an error at run time.

import std;

using namespace std;

int main()
{
	int uninitializedInt;
	int initializedInt{ 7 };

	println("{} is a random value", uninitializedInt);
	println("{} was assigned as an initial value", initializedInt);
}
