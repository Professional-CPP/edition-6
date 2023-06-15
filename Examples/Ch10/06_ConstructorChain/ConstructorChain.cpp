import std;

using namespace std;

class Something
{
public:
	Something() { print("2"); }
	virtual ~Something() { print("2"); }
};

class Base
{
public:
	Base() { print("1"); }
	virtual ~Base() { print("1"); }
};

class Derived : public Base
{
public:
	Derived() { print("3"); }
	virtual ~Derived() override { print("3"); }

private:
	Something m_dataMember;
};


int main()
{
	{
		Derived myDerived;
	}
	
	println("");

	{
		Base* ptr{ new Derived{} };
		delete ptr;
	}
}
