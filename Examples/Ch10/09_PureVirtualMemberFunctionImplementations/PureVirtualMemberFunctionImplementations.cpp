import std;

using namespace std;

class Base
{
public:
	virtual void doSomething() = 0; // Pure virtual member function.
};

// An out-of-class implementation of a pure virtual member function.
void Base::doSomething() { println("Base::doSomething()"); }

class Derived : public Base
{
public:
	void doSomething() override
	{
		// Call pure virtual member function implementation from base class.
		Base::doSomething();
		println("Derived::doSomething()");
	}
};

int main()
{
	Derived derived;
	Base& base{ derived };
	base.doSomething();
}
