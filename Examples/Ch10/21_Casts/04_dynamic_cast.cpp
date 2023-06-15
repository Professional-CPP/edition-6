import std;

using namespace std;

class Base
{
public:
	virtual ~Base() = default;
};

class Derived : public Base
{
public:
	virtual ~Derived() = default;
};

int main()
{
	Base* b;
	Derived* d{ new Derived{} };

	b = d;
	d = dynamic_cast<Derived*>(b);

	Base base;
	Derived derived;

	Base& br{ base };

	try {
		Derived& dr{ dynamic_cast<Derived&>(br) };
	} catch (const bad_cast&) {
		println("Bad cast!");
	}
}
