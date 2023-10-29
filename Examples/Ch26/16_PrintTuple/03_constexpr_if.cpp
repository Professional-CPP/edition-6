import std;

using namespace std;

template <typename TupleType, int n>
class TuplePrintHelper
{
public:
	TuplePrintHelper(const TupleType& t) {
		if constexpr (n > 1) {
			TuplePrintHelper<TupleType, n - 1> tp{ t };
		}
		println("{}", get<n - 1>(t));
	}
};

template <typename T>
void tuplePrint(const T& t)
{
	TuplePrintHelper<T, tuple_size<T>::value> tph{ t };
}

int main()
{
	tuple t1{ 167, "Testing"s, false, 2.3 };
	tuplePrint(t1);
}