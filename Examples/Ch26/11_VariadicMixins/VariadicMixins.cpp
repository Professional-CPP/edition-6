import std;

using namespace std;

class Mixin1
{
public:
	explicit Mixin1(int i) : m_value{ i } {}
	virtual void mixin1Func() { println("Mixin1: {}", m_value); }

private:
	int m_value;
};

class Mixin2
{
public:
	explicit Mixin2(int i) : m_value{ i } {}
	virtual void mixin2Func() { println("Mixin2: {}", m_value); }

private:
	int m_value;
};

template <typename... Mixins>
class MyClass : public Mixins...
{
public:
	explicit MyClass(const Mixins&... mixins) : Mixins{ mixins }... {}
	virtual ~MyClass() = default;
};

int main()
{
	MyClass<Mixin1, Mixin2> a{ Mixin1 { 11 }, Mixin2 { 22 } };
	a.mixin1Func();
	a.mixin2Func();

	MyClass<Mixin1> b{ Mixin1 { 33 } };
	b.mixin1Func();
	//b.mixin2Func();    // Error: does not compile.

	MyClass<> c;
	//c.mixin1Func();    // Error: does not compile.
	//c.mixin2Func();    // Error: does not compile.
}
