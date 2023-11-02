import std;

using namespace std;

class SubObject
{
	public:
		explicit SubObject(int i)
		{
			throw runtime_error{ "Exception by SubObject ctor" };
		}
};

class MyClass
{
	public:
		MyClass();
	private:
		int* m_data{ nullptr };
		SubObject m_subObject;
};

MyClass::MyClass()
try
	: m_data{ new int[42]{ 1, 2, 3 } }, m_subObject{ 42 }
{
	/* ... constructor body ... */
}
catch (const exception& e)
{
	// Cleanup memory.
	delete[] m_data;
	m_data = nullptr;
	println(cerr, "function-try-block caught: '{}'", e.what());
}

int main()
{
	try {
		MyClass m;
	} catch (const exception& e) {
		println(cerr, "main() caught: '{}'", e.what());
	}
}
