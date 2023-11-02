import std;

class Base
{
public:
	virtual ~Base() = default;
	Base() = default;
	explicit Base(int i) {}
};

class Derived : public Base
{
public:
	using Base::Base;
};

int main()
{
	Base base{ 1 };          // OK, calls integer Base ctor.
	Derived derived1{ 2 };   // OK, calls inherited integer Base ctor.
	Derived derived2;        // OK, calls inherited default Base ctor.
}
