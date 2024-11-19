#include <functional>

using namespace std;

void overloaded(int /* num */) {}
void overloaded(float /* f */) {}

int main()
{
	// Bind overloaded function
	//auto f3{ bind(overloaded, placeholders::_1) };					// ERROR
	auto f4{ bind((void(*)(float))overloaded, placeholders::_1) };	// OK
}

