import std;

using namespace std;

class Base
{
public:
	void someFunction() {}

protected:
	int m_protectedInt{ 0 };

private:
	int m_privateInt{ 0 };
};

class Derived : public Base
{
public:
	void someOtherFunction()
	{
		println("I can access base class data member m_protectedInt.");
		println("Its value is {}", m_protectedInt);
		//println("The value of m_privateInt is {}", m_privateInt); // Error!
	}
};

int main()
{
	Derived myDerived;
	myDerived.someFunction();
	myDerived.someOtherFunction();

	Base myBase;
	//myBase.someOtherFunction();  // Error! Base doesn't have a someOtherFunction().

	Base* base{ new Derived{} }; // Create Derived, store in Base pointer.

	//base->someOtherFunction();  // Error! Base doesn't have a someOtherFunction().
}
