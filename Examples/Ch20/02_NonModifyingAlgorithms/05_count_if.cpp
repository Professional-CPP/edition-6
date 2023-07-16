import std;

using namespace std;

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int value{ 3 };
	auto tally{ count_if(cbegin(values), cend(values),
		[value](int i) { return i > value; }) };
	println("Found {} values > {}.", tally, value);
}