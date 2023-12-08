import std;

using namespace std;

int main()
{
	auto power{ [](this auto& self, double value, int exponent) {
		if (exponent == 0) { return 1.0; }
		else if (exponent < 0) { return 1.0 / self(value, -exponent); }
		else { return value * self(value, exponent - 1); }
	} };

	const double value{ 2.0 };
	for (int exponent{ -10 }; exponent <= 10; ++exponent) {
		println("{}^{} = {}", value, exponent, power(value, exponent));
	}
}
