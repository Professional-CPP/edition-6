import std;

using namespace std;

template <typename Tuple, size_t... Indices>
void tuplePrintHelper(const Tuple& t, index_sequence<Indices...>)
{
	(println("{}", get<Indices>(t)), ...);
}

template <typename... Args>
void tuplePrint(const tuple<Args...>& t)
{
	tuplePrintHelper(t, index_sequence_for<Args...>());
}

int main()
{
	tuple t1{ 167, "Testing"s, false, 2.3 };
	tuplePrint(t1);
}