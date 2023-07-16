import std;

using namespace std;

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	println("Before: {:n}", values);

	ranges::for_each(values | views::filter([](int value) { return value % 2 == 0; }),
		[](int& value) { value *= 10; });
	println("After:  {:n}", values);
}
