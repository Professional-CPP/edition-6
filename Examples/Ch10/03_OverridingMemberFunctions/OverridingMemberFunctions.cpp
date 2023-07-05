import std;

using namespace std;

class Base
{
public:
	virtual void someFunction();

protected:
	int m_protectedInt{ 0 };

private:
	int m_privateInt{ 0 };
};

void Base::someFunction()
{
	println("This is Base's version of someFunction().");
}



class Derived : public Base
{
public:
	void someFunction() override; // Overrides Base's someFunction()

	virtual void someOtherFunction()
	{
		println("I can access base class data member m_protectedInt.");
		println("Its value is {}", m_protectedInt);
		//println("The value of m_privateInt is {}", m_privateInt); // Error!
	}
};

void Derived::someFunction()
{
	println("This is Derived's version of someFunction().");
}



int main()
{
	{
		Base myBase;
		myBase.someFunction();  // Calls Base's version of someFunction().
	}

	{
		Derived myDerived;
		myDerived.someFunction();   // Calls Derived's version of someFunction()
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		ref.someFunction();   // Calls Derived's version of someFunction()
	}

	{
		Derived myDerived;
		Base& ref{ myDerived };
		myDerived.someOtherFunction();  // This is fine.
		// ref.someOtherFunction();     // Error
	}

	{
		Derived myDerived;
		Base assignedObject{ myDerived };  // Assigns a Derived to a Base.
		assignedObject.someFunction();     // Calls Base's version of someFunction()
	}
}
