import std;

int main()
{
	int i1{ -7 };
	signed int i2{ -6 };
	signed i3{ -5 };

	short s1{ 13 };
	short int s2{ 14 };
	signed short s3{ 15 };
	signed short int s4{ 16 };

	long l{ -7L };

	long long ll{ 14LL };

	unsigned int ui{ 2U };
	unsigned uj{ 5U };
	unsigned short us{ 23U };
	unsigned long ul{ 5400UL };
	unsigned long long ull{ 140ULL };

	float f{ 7.2f };

	double d{ 7.2 };

	long double ld{ 16.98L };

	char ch{ 'm' };

	char8_t c8{ u8'm' };
	char16_t c16{ u'm' };
	char32_t c32{ U'm' };

	wchar_t w{ L'm' };

	bool b1{ true };

	std::byte b2{ 42 };
}
