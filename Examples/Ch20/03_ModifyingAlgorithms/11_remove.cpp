import std;

using namespace std;

void removeEmptyStrings(vector<string>& strings)
{
	auto it{ remove_if(begin(strings), end(strings),
		[](const string& str) { return str.empty(); }) };
	// Erase the removed elements.
	strings.erase(it, end(strings));
}

void removeEmptyStringsWithoutAlgorithms(vector<string>& strings)
{
	for (auto iter{ begin(strings) }; iter != end(strings); ) {
		if (iter->empty()) {
			iter = strings.erase(iter);
		} else {
			++iter;
		}
	}
}

int main()
{
	vector<string> myVector{ "", "one", "", "two", "three", "four" };

	println("{:n}", myVector);
	removeEmptyStrings(myVector);
	println("{:n}", myVector);
}
