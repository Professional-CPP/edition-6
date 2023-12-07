import std;

using namespace std;

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
	typename iterator_traits<IteratorType>::value_type temp;
	temp = *it;
	//auto temp{ *it };
	println("{}", temp);
}

int main()
{
	vector v{ 5 };
	iteratorTraitsTest(cbegin(v));
}
