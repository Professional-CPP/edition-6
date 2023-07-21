import std;

using namespace std;

int main()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1{ 16, "Test", true };
	//tuple t1{ 16, "Test"s, true };  // Using CTAD

	// Starting with C++23, println() has full support for tuple.
	println("t1 = {}", t1);
	
	println("t1 = ({}, {}, {})", get<0>(t1), get<1>(t1), get<2>(t1));

	println("Type of get<1>(t1) = {}", typeid(get<1>(t1)).name());

	println("Type of element with index 2 = {}",
		typeid(tuple_element<2, MyTuple>::type).name());

	println("String = {}", get<string>(t1));

	println("Tuple Size = {}", tuple_size<MyTuple>::value);
	println("Tuple Size = {}", tuple_size<decltype(t1)>::value);

	double d{ 3.14 };
	string str1{ "Test" };
	// t2 will be tuple<int, double&, const double&, string&>
	tuple t2{ 16, ref(d), cref(d), ref(str1) };  // Using CTAD
	// Or using make_tuple().
	//auto t2{ make_tuple(16, ref(d), cref(d), ref(str1)) };

	println("d = {}", d);
	get<1>(t2) *= 2;
	//get<2>(t2) *= 2;    // ERROR because of cref().
	println("d = {}", d);
}