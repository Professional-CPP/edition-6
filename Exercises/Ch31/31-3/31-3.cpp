import std;

using namespace std;

int sum(int* values, int count)
{
	int total{ 0 };
	for (int i{ 0 }; i <= count; ++i) { total += values[i]; }
	//// The previous line contains a bug.
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
	int total{ sum(values, sizeof(values)) };
	//// The previous line contains another bug.
	//// sizeof(values) returns the size in bytes of the values array.
	//// This size in bytes in 12, which is not what you want to pass to sum().
	//// You should use size(values) instead of sizeof(values).
	//// Correct line:
	////int total{ sum(values, size(values)) };
	println("{}", total);
}
