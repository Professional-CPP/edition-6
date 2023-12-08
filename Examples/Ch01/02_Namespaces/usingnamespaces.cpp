import std;

namespace mycode {
	void foo()
	{
		std::println("foo() called in the mycode namespace");
	}
}

using namespace mycode;

int main()
{
	mycode::foo();	// Calls the "foo" function in the "mycode" namespace
	foo();			// implies mycode::foo();
}
