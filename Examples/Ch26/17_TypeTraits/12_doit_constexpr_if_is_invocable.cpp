import std;

using namespace std;

class IsDoable
{
public:
	void doit() const { println("IsDoable::doit()"); }
};

class Derived : public IsDoable
{
};

template<typename T>
void callDoit(const T& [[maybe_unused]] t)
{
	if constexpr (is_invocable_v<decltype(&IsDoable::doit), T>) {
		t.doit();
	} else {
		println("Cannot call doit()!");
	}
}

int main()
{
	Derived d;
	callDoit(d);
	callDoit(123);
}
