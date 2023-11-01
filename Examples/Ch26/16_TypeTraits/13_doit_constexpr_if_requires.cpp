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
void callDoit(const T& t)
{
	if constexpr (requires { t.doit(); }) {
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
