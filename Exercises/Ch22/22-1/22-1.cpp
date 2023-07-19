import std;

using namespace std;
using namespace std::chrono;

int main()
{
	seconds d1{ 42 };
	duration<double, ratio<60>> d2{ 1.5 };
	auto d3{ d1 + d2 };
	println("{} or {}.", d3,
		duration<double, ratio<60>>{ d3 });
}