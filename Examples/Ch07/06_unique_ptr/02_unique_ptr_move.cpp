import std;

using namespace std;

class Foo
{
public:
	Foo(unique_ptr<int> data) : m_data{ move(data) } { }

private:
	unique_ptr<int> m_data;
};

int main()
{
	auto myIntSmartPtr{ make_unique<int>(42) };
	Foo f{ move(myIntSmartPtr) };
}
