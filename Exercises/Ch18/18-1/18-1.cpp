import std;

using namespace std;

int main()
{
	vector<int> values{ 2, 5 };

	// 1
	values.insert(begin(values) + 1, 3);
	values.insert(begin(values) + 2, 4);

	// 2
	vector<int> v2{ 0, 1 };
	values.insert(begin(values), cbegin(v2), cend(v2));

	// 3
	vector<int> v3;
	for (auto riter{ crbegin(values) }; riter != crend(values); ++riter) {
		v3.push_back(*riter);
	}

	// 4
	println("{}", v3);

	// 5
	for (const auto& element : v3) {
		print("{} ", element);
	}
	println("");
}
