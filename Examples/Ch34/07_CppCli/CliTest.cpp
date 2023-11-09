#include <iostream>

using namespace System;
using namespace MyLibrary;

int main(array<System::String^>^ args)
{
	MyClass^ instance{ gcnew MyClass() };
	auto result{ instance->DoubleIt(1.2) };
	std::cout << result << std::endl;

	result = instance->TripleIt(11.22);
	std::cout << result << std::endl;
}

