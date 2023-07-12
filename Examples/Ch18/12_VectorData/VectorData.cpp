import std;

using namespace std;

int main()
{
	vector vec{ 1, 2, 3 };
	int* data1{ vec.data() };
	int* data2{ data(vec) };
}