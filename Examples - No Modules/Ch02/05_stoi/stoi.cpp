#include <print>
#include <string>
#include <cstddef>

using namespace std;

int main()
{
	const string toParse{ "   123USD" };
	size_t index{ 0 };
	int value{ stoi(toParse, &index) };
	println("Parsed value: {}", value);
	println("First non-parsed character: '{}'", toParse[index]);
}