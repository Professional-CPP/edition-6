import std;

using namespace std;

template<typename... Values>
auto sumValues(const Values&... values)
{
	return (... + values);
}

int main()
{
	println("{}", sumValues(1, 2, 3.3));
	println("{}", sumValues(1));
	//println("{}", sumValues());  // Does not compile!
}
