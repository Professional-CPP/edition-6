import std;

using namespace std;

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	erase_if(values,
		[](int value) { return value % 2; });

	println("{}", values);
}