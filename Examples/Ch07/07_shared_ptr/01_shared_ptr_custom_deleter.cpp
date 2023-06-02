import std;

using namespace std;

int* my_alloc(int value)
{
	return new int{ value };
}

void my_free(int* p)
{
	delete p;
}

int main()
{
	shared_ptr<int> myIntSmartPtr{ my_alloc(42), my_free };
}
