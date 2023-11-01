import std;

using namespace std;

template <typename TupleType, int N>
class TuplePrintHelper
{
public:
	explicit TuplePrintHelper(const TupleType& t) {
		TuplePrintHelper<TupleType, N - 1> tp{ t };
		println("{}", get<N - 1>(t));
	}
};

template <typename TupleType>
class TuplePrintHelper<TupleType, 0>
{
public:
	explicit TuplePrintHelper(const TupleType&) { }
};

template <typename T>
void tuplePrint(const T& t)
{
	TuplePrintHelper<T, tuple_size<T>::value> tph{ t };
}

int main()
{
	tuple t1{ 16, "Test"s, true };
	tuplePrint(t1);
}
