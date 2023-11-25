import std;

using namespace std;

constexpr int getArraySize()
{
	return 32;
}


void log(string_view message)
{
	print("{}", message);
}

constexpr int computeSomething(bool someFlag)
{
	if (someFlag)
	{
		log("someFlag is true");
		return 42;
	}
	else
	{
		return 84;
	}
}


int main()
{
	{
		int myArray[getArraySize()];	 // OK
		println("Size of array = {}", size(myArray));
	}

	{
		int myArray[getArraySize() + 1]; // OK
		println("Size of array = {}", size(myArray));
	}

	{
		constexpr auto value1{ computeSomething(false) };
		//constexpr auto value2{ computeSomething(true) }; // Error: doesn't compile!
		const auto value3{ computeSomething(true) };
	}
}
