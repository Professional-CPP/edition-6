import std;

using namespace std;

int main()
{
	// Define a compile-time rational number.
	using r1 = ratio<1, 60>;

	// Get numerator and denominator.
	intmax_t num{ r1::num };
	intmax_t den{ r1::den };
	println("1) r1 = {}/{}", num, den);

	// Add two rational numbers.
	using r2 = ratio<1, 30>;
	println("2) r2 = {}/{}", r2::num, r2::den);
	using result = ratio_add<r1, r2>::type;
	println("3) sum = {}/{}", result::num, result::den);

	// Compare two rational numbers.
	using res = ratio_less<r2, r1>;
	println("4) r2 < r1: {}", res::value);
}
