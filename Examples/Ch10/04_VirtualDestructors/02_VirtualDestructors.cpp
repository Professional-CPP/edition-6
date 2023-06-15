import std;

using namespace std;

class Base
{
public:
	Base() = default;
	virtual ~Base() = default;
};

class Derived : public Base
{
public:
	Derived()
	{
		m_string = new char[30];
		println("m_string allocated");
	}

	~Derived() override
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
	delete ptr;                   // m_string is deallocated here.
}
