template <typename T>
constexpr T pi{ T{ 3.141592653589793238462643383279502884 } };

int main()
{
	float piFloat{ pi<float> };
	auto piLongDouble{ pi<long double> };
}
