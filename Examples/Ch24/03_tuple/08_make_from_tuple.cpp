import std;

using namespace std;

class Foo
{
public:
	explicit Foo(string str, int i) : m_str{ move(str) }, m_int{ i } {}

private:
	string m_str;
	int m_int;
};

int main()
{
	tuple myTuple{ "Hello world.", 42 };
	auto foo{ make_from_tuple<Foo>(myTuple) };
}
