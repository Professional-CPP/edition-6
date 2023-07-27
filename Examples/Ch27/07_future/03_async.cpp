import std;

using namespace std;

int calculateSum(int a, int b)
{
	return a + b;
}

int main()
{
	auto myFuture{ async(calculateSum, 39, 3) };
	//auto myFuture{ async(launch::async, calculateSum, 39, 3) };
	//auto myFuture{ async(launch::deferred, calculateSum, 39, 3) };

	// Do some more work...

	// Get the result.
	int result{ myFuture.get() };
	println("Result: {}", result);
}
