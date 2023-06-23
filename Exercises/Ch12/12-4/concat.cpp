import std;

using namespace std;

template <typename T>
concept SupportsToString = requires(const T& t) { to_string(t); };

auto concat(const SupportsToString auto& t1, const SupportsToString auto& t2)
{
	return to_string(t1) + to_string(t2);
}

int main()
{
	println("{}", concat(1, 2.2));
}