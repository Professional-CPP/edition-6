import std;

using namespace std;

class IsDoable
{
public:
	virtual void doit() const { println("IsDoable::doit()"); }
};

class Derived : public IsDoable
{
};

template<typename T>
enable_if_t<is_base_of_v<IsDoable, T>, void>
	callDoit(const T& t)
{
	t.doit();
}

template<typename T>
enable_if_t<!is_base_of_v<IsDoable, T>, void>
	callDoit(const T&)
{
	println("Cannot call doit()!");
}

int main()
{
	Derived d;
	callDoit(d);
	callDoit(123);
}
