import std;

using namespace std;

template <typename T1, typename T2>
void same(const T1& t1, const T2& t2)
{
	println("'{}' and '{}' are different types.", t1, t2);
}
template <typename T>
void same(const T& t1, const T& t2)
{
	println("'{}' and '{}' are the same type.", t1, t2);
}

int main()
{
	same(1, 32);
	same(1, 3.01);
	same(3.01, "Test"s);
}
