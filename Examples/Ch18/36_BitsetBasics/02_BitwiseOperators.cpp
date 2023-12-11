import std;

using namespace std;

int main()
{
	auto str1{ "0011001100" };
	auto str2{ "0000111100" };
	bitset<10> bitsOne{ str1 };
	bitset<10> bitsTwo{ str2 };

	auto bitsThree{ bitsOne & bitsTwo };
	println("{}", bitsThree.to_string());
	bitsThree <<= 4;
	println("{}", bitsThree.to_string());
}
