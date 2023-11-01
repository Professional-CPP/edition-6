import std;

using namespace std;

template<typename T, typename... U>
concept SameTypes = (std::same_as<T, U> && ...);

template<typename T, typename... Values>
	requires SameTypes<T, Values...>
auto sumValues(const T& init, const Values&... values)
{
	return (init + ... + values);
}

int main()
{
	println("{}", sumValues(1.1, 2.2, 3.3)); // OK: 3 doubles, output is 6.6
	println("{}", sumValues(1));             // OK: 1 integer, output is 1
	println("{}", sumValues("a"s, "b"s));    // OK: 2 strings, output is ab
	//println("{}", sumValues(1, 2.2, 3.3)); // Error
}
