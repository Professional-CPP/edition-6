import std;

using namespace std;

void atomicMin(atomic<int>& a, int b)
{
	int expected{ a.load() };
	int desired{ min(expected, b) };
	while (!a.compare_exchange_strong(expected, desired)) {
		desired = min(expected, b);
	}
}

int main()
{
	atomic<int> value1{ 10 };
	atomicMin(value1, 42);
	println("Min(10, 42) = {}", value1.load());

	atomic<int> value2{ 84 };
	atomicMin(value2, 42);
	println("Min(84, 42) = {}", value2.load());
}
