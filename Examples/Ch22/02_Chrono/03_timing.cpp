import std;

using namespace std;
using namespace std::chrono;

int main()
{
	// Get the start time.
	auto start{ steady_clock::now() };

	// Execute code that you want to time.
	const int numberOfIterations{ 10'000'000 };
	double d{ 0 };
	for (int i{ 0 }; i < numberOfIterations; ++i) {
		d += sqrt(abs(sin(i) * cos(i)));
	}

	// Get the end time and calculate the difference.
	auto end{ steady_clock::now() };
	auto diff{ end - start };

	// Use the calculated result, otherwise the compiler might
	// optimize away the entire loop!
	println("d = {}", d);

	// Convert the difference into milliseconds and output to the console.
	println("Total: {}", duration<double, milli> { diff });
	// Use duration_cast() if you don't need fractional milliseconds.
	println("Total: {}", duration_cast<milliseconds>(diff));
	// Print the time per iteration in nanoseconds.
	println("{} per iteration", duration<double, nano> { diff / numberOfIterations });
}
