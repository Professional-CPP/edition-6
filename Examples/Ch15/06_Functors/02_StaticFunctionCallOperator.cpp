import std;

using namespace std;

class Squarer
{
public:
	static constexpr int operator()(int value) noexcept
	{
		return value * value;
	}
};

int main()
{
	int x{ 3 };

	int xSquared{ Squarer::operator()(x) };
	int xSquaredAgain{ Squarer{}(xSquared) };

	println("{} squared is {}, and squared again is {}.", x, xSquared, xSquaredAgain);
}
