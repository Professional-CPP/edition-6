import std;

using namespace std;

int sum(int* values, int count)
{
	int total{ 0 };
	//// The following line contains the bug
	for (int i{ 0 }; i <= count; ++i) { total += values[i]; }
	//// The for loop end condition must be 
	//// i < count
	//// instead of
	//// i <= count
	//// Correct line:
	////for (int i{ 0 }; i < count; ++i) { total += values[i]; }
	return total;
}

int main()
{
	int values[]{ 1, 2, 3 };
	int total{ sum(values, size(values)) };
	println("{}", total);
}
