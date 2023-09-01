#include <cstddef>

void func(int i) { /* ... */ }

int main()
{
	func(NULL);
	//func(nullptr); // Compilation error.
}
