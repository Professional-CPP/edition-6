import std;

using namespace std;

int main()
{
	auto fibonacci = [](this auto& self, int n) {
		if (n < 2) {
			return n;
		}
		return self(n - 1) + self(n - 2);
	};

	println("First 20 Fibonacci numbers:");
	for (int i{ 0 }; i < 20; ++i) {
		print("{} ", fibonacci(i));
	}
}