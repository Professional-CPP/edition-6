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
	tuplePrintHelper(t, make_index_sequence<sizeof...(Args)>{});
}

int main()
{
	tuple t1{ 16, "Test"s, true };
	tuplePrint(t1);
}