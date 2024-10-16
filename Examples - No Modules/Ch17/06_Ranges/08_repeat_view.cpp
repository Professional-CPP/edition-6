#include <print>
#include <ranges>
#include <string_view>

using namespace std;

void printRange(string_view message, auto&& range)
{
	println("{}{:n}", message, range);
}

int main()
{
	// views::repeat
	printRange("Repeating view: ", views::repeat(42, 5));
}
