import std;
using namespace std;

using errorcode = int;

errorcode my_alloc(int value, int** data)
{
	*data = new int{ value };
	println("Allocated");
	return 0;
}

errorcode my_free(int* data)
{
	delete data;
	println("Freed");
	return 0;
}

int main()
{
	{
		unique_ptr<int, decltype(&my_free)> myIntSmartPtr(nullptr, my_free);
		int* data{ nullptr };
		my_alloc(42, &data);
		myIntSmartPtr.reset(data);
	}

	{
		unique_ptr<int, decltype(&my_free)> myIntSmartPtr(nullptr, my_free);
		my_alloc(42, inout_ptr(myIntSmartPtr));
	}
}
