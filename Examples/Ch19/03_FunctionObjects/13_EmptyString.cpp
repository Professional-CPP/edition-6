import std;

using namespace std;

template<predicate<const string&> Matcher>
void printMatchingStrings(const vector<string>& strings, Matcher matcher)
{
	for (const auto& string : strings) {
		if (matcher(string)) {
			print("'{}' ", string);
		}
	}
}

int main()
{
	vector<string> values{ "Hello", "", "", "World", "!" };
	printMatchingStrings(values, not_fn(mem_fn(&string::empty)));
}
