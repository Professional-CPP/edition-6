import std;

using namespace std;

unsigned long long fibonacci(unsigned int n)
{
	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }

	unsigned long long a{ 0 };
	unsigned long long b{ 1 };

	unsigned long long result{ 0 };
	for (unsigned int i{ 1 }; i < n; ++i) {
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main()
{
	// Indices of Fibonacci numbers to calculate.
	vector fibonacciNumbersToCalculate{ 4, 9, 14, 17 };

	// Launch threads to calculate the required numbers concurrently.
	vector<future<unsigned long long>> futures;
	for (auto& index : fibonacciNumbersToCalculate) {
		futures.push_back(async(launch::async, fibonacci, index));
	}

	// Wait for all threads to finish and collect results.
	vector<unsigned long long> fibonacciNumbers;
	for (auto& f : futures) {
		fibonacciNumbers.push_back(f.get());
	}

	// Print the calculated numbers.
	println("Fibonacci numbers: {}", fibonacciNumbers);

	// Calculate their sum.
	println("Their sum: {}", ranges::fold_left(fibonacciNumbers, 0ull, std::plus<>{}));
}
