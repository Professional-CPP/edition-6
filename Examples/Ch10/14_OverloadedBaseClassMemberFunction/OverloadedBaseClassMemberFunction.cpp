import std;

using namespace std;

class Base
{
public:
	virtual ~Base() = default;
	virtual void overload() { println("Base's overload()"); }
	virtual void overload(int i) { println("Base's overload(int i)"); }
};

class Derived : public Base
{
public:
	//using Base::overload;
	void overload() override { println("Derived's overload()"); }
};

int main()
{
	{
		Derived myDerived;
		//myDerived.overload(2); // Error! No matching member function for overload(int).
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		ref.overload(7);
	}
}
