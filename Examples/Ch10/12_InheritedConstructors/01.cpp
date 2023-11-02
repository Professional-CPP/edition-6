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
	Derived(int i) : Base(i) {}
};

int main()
{
	Base base{ 1 };          // OK, calls integer Base ctor.
	Derived derived1{ 2 };   // OK, calls integer Derived ctor.
	//Derived derived2;      // Error, Derived does not have a default ctor.
}
