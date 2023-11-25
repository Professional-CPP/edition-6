import std;

using namespace std;

class Base
{
public:
	void someFunction()
	{
		println("Base::someFunction()");
	}

protected:
	int m_protectedInt{ 0 };

private:
	int m_privateInt{ 0 };
};

class Derived : public Base
{
public:
	void someFunction()
	{
		println("Derived::someFunction()");
	}

	void someOtherFunction()
	{
		println("I can access base class data member m_protectedInt.");
		println("Its value is {}", m_protectedInt);
		//println("The value of m_privateInt is {}", m_privateInt); // Error!
	}
};

int main()
{
	{
		Derived myDerived;
		myDerived.someFunction();
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		ref.someFunction();
	}
}
