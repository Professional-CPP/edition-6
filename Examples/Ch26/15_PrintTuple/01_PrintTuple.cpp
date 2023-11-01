import std;

using namespace std;

template <typename TupleType, int N>
class TuplePrint
{
public:
	explicit TuplePrint(const TupleType& t) {
		TuplePrint<TupleType, N - 1> tp{ t };
		println("{}", get<N - 1>(t));
	}
};

template <typename TupleType>
class TuplePrint<TupleType, 0>
{
public:
	explicit TuplePrint(const TupleType&) { }
};

int main()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1{ 16, "Test", true };
	TuplePrint<MyTuple, tuple_size<MyTuple>::value> tp{ t1 };
}
