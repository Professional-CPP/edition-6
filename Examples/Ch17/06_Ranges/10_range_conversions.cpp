import std;

using namespace std;

int main()
{
	// Convert a vector to a set with the same element type.
	vector vec{ 33, 11, 22 };
	auto s1{ ranges::to<set>(vec) };
	println("{:n}", s1); // 11, 22, 33

	// Convert a vector of integers to a set of doubles, using the pipe operator.
	auto s2{ vec | ranges::to<set<double>>() };
	println("{:n}", s2); // 11, 22, 33

	// Convert a vector of integers to a set of doubles, using from_range constructor.
	set<double> s3{ from_range, vec };
	println("{:n}", s3); // 11, 22, 33

	// Lazily generate the integers from 10 to 14, divide these by 2,
	// and store the result in a vector of doubles.
	auto vec2{ views::iota(10, 15)
		| views::transform([](const auto& v) { return v / 2.0; })
		| ranges::to<vector<double>>() };
	println("{:n}", vec2); // 5, 5.5, 6, 6.5, 7

	// Use views::split() and views::transform() to create a view
	// containing individual words of a string, and then convert
	// the resulting view to a vector of strings containing all the words.
	string lorem{ "Lorem ipsum dolor sit amet" };
	auto words{ lorem | views::split(' ')
		| views::transform([](const auto& v) { return string{ from_range, v }; })
		| ranges::to<vector>() };
	println("{:n:?}", words); // "Lorem", "ipsum", "dolor", "sit", "amet"

	// Demonstrate xyz_range() member functions.
	vector<int> vec3;
	vec3.append_range(views::iota(10, 15));
	println("{:n}", vec3); // 10, 11, 12, 13, 14
	vec3.insert_range(begin(vec3), views::iota(10, 15) | views::reverse);
	println("{:n}", vec3); // 14, 13, 12, 11, 10, 10, 11, 12, 13, 14
}
