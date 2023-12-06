import std;

using namespace std;

template <typename TupleType, int N = tuple_size<TupleType>::value>
void tuplePrint(const TupleType& t)
{
	if constexpr (N > 1) {
		tuplePrint<TupleType, N - 1>(t);
	}
	println("{}", get<N - 1>(t));
}

int main()
{
	tuple t1{ 16, "Test"s, true };
	tuplePrint(t1);
}
