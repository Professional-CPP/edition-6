import std;

using namespace std;

int main()
{
	vector v1{ 1, 2, 3, 4 };
	vector v2{ 9, 8, 7, 6 };
	println("{}", inner_product(cbegin(v1), cend(v1), cbegin(v2), 0));
}
