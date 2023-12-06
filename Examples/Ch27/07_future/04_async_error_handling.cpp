import std;

using namespace std;

int calculate()
{
	throw runtime_error{ "Exception thrown from calculate()." };
}

int main()
{
	// Use the launch::async policy to force asynchronous execution.
	auto myFuture{ async(launch::async, calculate) };

	// Do some more work...

	// Get the result.
	try {
		int result{ myFuture.get() };
		println("Result: {}", result);
	} catch (const exception& ex) {
		println("Caught exception: {}", ex.what());
	}
}
