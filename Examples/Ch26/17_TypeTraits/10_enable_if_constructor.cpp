import std;

using namespace std;

template<typename T>
class Foo
{
public:
	template<typename U = T>
	Foo(const T& t, enable_if_t<is_integral_v<U>>* = nullptr)
		: m_t{ t }
	{
		println("Foo's integral constructor ({}).", m_t);
	}

	template<typename U = T>
	Foo(const T& t, enable_if_t<is_floating_point_v<U>>* = nullptr)
		: m_t{ t }
	{
		println("Foo's floating point constructor ({}).", m_t);
	}

private:
	T m_t;
};

int main()
{
	Foo<long> f1{ 1 };
	Foo<double> f2{ 1.2 };
}