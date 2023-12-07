import std;

using namespace std;

template<input_iterator Iter, typename Distance>
void myAdvance(Iter& iter, Distance n)
{
	while (n > 0) { ++iter; --n; }
}

template<bidirectional_iterator Iter, typename Distance>
void myAdvance(Iter& iter, Distance n)
{
	while (n > 0) { ++iter; --n; }
	while (n < 0) { --iter; ++n; }
}

template<random_access_iterator Iter, typename Distance>
void myAdvance(Iter& iter, Distance n)
{
	iter += n;
}

template<typename Iter>
void testAdvance(Iter iter)
{
	print("*iter = {} | ", *iter);
	myAdvance(iter, 3); print("3 ahead = {} | ", *iter);
	myAdvance(iter, -2); println("2 back = {}", *iter);
}

int main()
{
	vector vec{ 1, 2, 3, 4, 5, 6 };
	testAdvance(begin(vec));

	list lst{ 1, 2, 3, 4, 5, 6 };
	testAdvance(begin(lst));
}
