import std;

using namespace std;

template <typename TupleType, int N>
class TuplePrintHelper
{
public:
	explicit TuplePrintHelper(const TupleType& t) {
		if constexpr (N > 1) {
			TuplePrintHelper<TupleType, N - 1> tp{ t };
		}
		println("{}", get<N - 1>(t));
	}
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
