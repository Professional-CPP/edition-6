import std;

using namespace std;

void atomicallyMultiply(atomic<int>& a, int n)
{
	int expected{ a.load() };
	int desired{ n * expected };
	while (!a.compare_exchange_strong(expected, desired)) {
		desired = n * expected;
	}
}

int main()
{
	atomic<int> value{ 10 };
	println("Value = {}", value.load());
	atomicallyMultiply(value, 3);
	println("Result = {}", value.load());
}
