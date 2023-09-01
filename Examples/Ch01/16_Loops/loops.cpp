import std;

using namespace std;

int main()
{
	{
		// The while loop
		int i{ 0 };
		while (i < 5) {
			println("This is silly.");
			++i;
		}
	}

	println("");

	{
		// The do/while loop
		int i{ 100 };
		do {
			println("This is silly.");
			++i;
		} while (i < 5);
	}

	println("");

	{
		// The for loop
		for (int i{ 0 }; i < 5; ++i) {
			println("This is silly.");
		}
	}

	println("");

	{
		// The range-based for loop
		array arr{ 1, 2, 3, 4 };
		for (int i : arr) { println("{}", i); }
	}

	println("");

	{
		// The range-based for loop with initializer
		for (array arr{ 1, 2, 3, 4 }; int i : arr) { println("{}", i); }
	}
}