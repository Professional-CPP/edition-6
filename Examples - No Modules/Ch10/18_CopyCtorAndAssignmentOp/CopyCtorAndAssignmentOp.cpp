class Base
{
public:
	virtual ~Base() = default;
	Base() = default;
	Base(const Base& src) { }
};

class Derived : public Base
{
public:
	Derived() = default;

	Derived(const Derived& src) : Base{ src } { }

	Derived& operator=(const Derived& rhs)
	{
		if (&rhs == this) {
			return *this;
		}
		Base::operator=(rhs); // Calls parent's operator=.
		// Do necessary assignments for derived class.
		return *this;
	}
};

int main()
{
	Derived d1;
	Derived d2{ d1 };
	d2 = d1;
}
