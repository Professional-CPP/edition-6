import std;

using namespace std;

int* getData(int value)
{
	return new int{ value * 2 };
}

int main()
{
	int* data{ getData(21) };
	println("{}", *data);
	//// Memory leak! Memory for data is not deleted.
	//// Following statements need to be added:
	delete data;
	data = nullptr;

	data = getData(42);
	println("{}", *data);
	//// Memory leak! Memory for data is not deleted.
	//// Following statements need to be added:
	delete data;
	data = nullptr;
}