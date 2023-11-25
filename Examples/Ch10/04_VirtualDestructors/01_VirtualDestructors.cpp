import std;

using namespace std;

class Base
{
public:
	Base() = default;
	~Base() {}
};

class Derived : public Base
{
public:
	Derived()
	{
		m_string = new char[30];
		println("m_string allocated");
	}

	~Derived()
	{
		delete[] m_string;
		println("m_string deallocated");
	}

private:
	char* m_string;
};

int main()
{
	Base* ptr{ new Derived{} };   // m_string is allocated here.
	delete ptr; // ~Base is called, but not ~Derived because the destructor
				// is not virtual!
}
