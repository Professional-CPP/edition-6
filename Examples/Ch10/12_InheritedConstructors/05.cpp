import std;

class Base
{
public:
	virtual ~Base() = default;
	explicit Base(std::string_view str) : m_str{ str } {}
private:
	std::string m_str;
};

class Derived : public Base
{
public:
	using Base::Base;
	explicit Derived(int i) : Base{ "" }, m_int{ i } {}
private:
	int m_int{ 0 };
};


int main()
{
	Derived s1{ 2 };
	Derived s2{ "Hello World" };
}
