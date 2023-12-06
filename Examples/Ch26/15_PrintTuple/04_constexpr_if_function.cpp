import std;

using namespace std;

template <typename TupleType, int N>
void tuplePrintHelper(const TupleType& t)
{
	if constexpr (N > 1) {
		tuplePrintHelper<TupleType, N - 1>(t);
	}
	println("{}", get<N - 1>(t));
}

template <typename T>
void tuplePrint(const T& t)
{
	tuplePrintHelper<T, tuple_size<T>::value>(t);
}

int main()
{
	tuple t1{ 16, "Test"s, true };
	tuplePrint(t1);
}
