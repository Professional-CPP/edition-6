import std;

using namespace std;

template<input_iterator Iter>
void myPrint(Iter begin, Iter end)
{
	for (auto iter{ begin }; iter != end; ++iter) {
		print("{} ", *iter);
	}
}

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto iter{ cbegin(values) }; iter != cend(values); ++iter) {
		print("{} ", *iter);
	}
	println("");

	myPrint(cbegin(values), cend(values));
	println("");
}