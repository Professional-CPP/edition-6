import std;

using namespace std;

class Foo
{
public:
	Foo(double value);

private:
	double m_value{ 0 };
};

Foo::Foo(double value) : m_value{ value }
{
	println("Foo::m_value = {}", m_value);
}

class MyClass
{
public:
	MyClass(double value);

private:
	Foo m_foo;
	double m_value{ 0 };
};

MyClass::MyClass(double value)
	: m_value{ value }
	, m_foo{ m_value }
{
	println("MyClass::m_value = {}", m_value);
}

int main()
{
	MyClass instance{ 1.2 };
}