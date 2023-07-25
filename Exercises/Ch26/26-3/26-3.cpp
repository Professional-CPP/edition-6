import std;

using namespace std;

consteval unsigned long long fibonacci(unsigned int n)
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
	println("{}", fibonacci(0));
	println("{}", fibonacci(1));
	println("{}", fibonacci(2));
	println("{}", fibonacci(3));
	println("{}", fibonacci(4));
	println("{}", fibonacci(5));
	println("{}", fibonacci(6));
	println("{}", fibonacci(7));
	println("{}", fibonacci(8));
	println("{}", fibonacci(9));
	println("{}", fibonacci(10));
	println("{}", fibonacci(11));
}