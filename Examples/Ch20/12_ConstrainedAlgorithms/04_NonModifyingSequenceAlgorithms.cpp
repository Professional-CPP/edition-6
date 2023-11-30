import std;

using namespace std;

int main()
{
	vector values{ 11, 22, 33, 44, 55 };
	vector v{ 11, 22 };
	println("{} contains 33 = {}", values, ranges::contains(values, 33));
	println("{} contains {} = {}", values, v, ranges::contains_subrange(values, v));
	println("{} starts with {} = {}", values, v, ranges::starts_with(values, v));
}
