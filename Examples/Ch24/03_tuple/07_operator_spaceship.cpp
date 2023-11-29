import std;

using namespace std;

class Foo
{
public:
	explicit Foo(int i, string s, bool b)
		: m_int{ i }, m_str{ move(s) }, m_bool{ b }
	{
	}

	// Explicitly default operator<=>
	//auto operator<=>(const Foo& rhs) const = default;
	
	// Compare a subset of the data members.
	auto operator<=>(const Foo& rhs) const
	{
		return tie(m_int, m_str) <=> tie(rhs.m_int, rhs.m_str);
	}
private:
	int m_int;
	string m_str;
	bool m_bool;
};

int main()
{
	Foo f1{ 42, "Hello", false };
	Foo f2{ 42, "World", false };
	println("{}", (f1 < f2));  // Outputs true
	println("{}", (f2 > f1));  // Outputs true
}
