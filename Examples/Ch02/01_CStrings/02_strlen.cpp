import std;

using namespace std;

int main()
{
	char text1[]{ "abcdef" };
	size_t s1{ sizeof(text1) };  // is 7
	size_t s2{ strlen(text1) };  // is 6
	println("{}\n{}", s1, s2);

	const char* text2{ "abcdef" };
	size_t s3{ sizeof(text2) };  // is platform-dependent (e.g. 4 bytes for x86, 8 bytes for x64)
	size_t s4{ strlen(text2) };  // is 6
	println("{}\n{}", s3, s4);
}
