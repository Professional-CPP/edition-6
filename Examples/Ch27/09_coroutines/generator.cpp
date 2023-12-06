import std;

using namespace std;
using namespace std::chrono;

generator<int> getSequenceGenerator(int startValue, int numberOfValues)
{
	for (int i{ startValue }; i < startValue + numberOfValues; ++i) {
		// Print the local time to standard out, see Chapter 22.
		auto currentTime{ system_clock::now() };
		auto localTime{ current_zone()->to_local(currentTime) };
		print("{:%H:%M:%OS}: ", localTime);

		// Yield a value to the caller, and suspend the coroutine.
		co_yield i;
	}
}

int main()
{
	auto gen{ getSequenceGenerator(10, 5) };
	for (const auto& value : gen) {
		print("{} (Press enter for next value)", value);
		cin.ignore();
	}
}
