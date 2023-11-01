import std;

using namespace std;

template<typename T, typename... Values>
auto sumValues(const T& init, const Values&... values)
{
	return (init + ... + values);
}

int main()
{
	println("{}", sumValues(1, 2, 3.3));
	println("{}", sumValues(1));
	//println("{}", sumValues());  // Does not compile!
}
