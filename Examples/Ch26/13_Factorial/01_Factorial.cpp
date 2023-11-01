import std;

using namespace std;

template <int f>
class Factorial
{
public:
	static constexpr unsigned long long value{ f * Factorial<f - 1>::value };
};

template <>
class Factorial<0>
{
public:
	static constexpr unsigned long long value{ 1 };
};

int main()
{
	println("{}", Factorial<6>::value);
}
