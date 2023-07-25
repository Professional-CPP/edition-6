import std;

using namespace std;

template <typename TupleType, int n>
void tuplePrintHelper(const TupleType& t)
{
	if constexpr (n > 1) {
		tuplePrintHelper<TupleType, n - 1>(t);
	}
	println("{}", get<n - 1>(t));
}

template <typename T>
void tuplePrint(const T& t)
{
	tuplePrintHelper<T, tuple_size<T>::value>(t);
}

int main()
{
	tuple t1{ 167, "Testing"s, false, 2.3 };
	tuplePrint(t1);
}
