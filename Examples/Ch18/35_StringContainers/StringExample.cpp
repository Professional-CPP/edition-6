import std;

using namespace std;

int main()
{
	string myString;

	myString.insert(cend(myString), 'h');
	myString.insert(cend(myString), 'e');
	myString.push_back('l');
	myString.push_back('l');
	myString.push_back('o');

	for (const auto& letter : myString) {
		print("{}", letter);
	}
	println("");

	for (auto it{ cbegin(myString) }; it != cend(myString); ++it) {
		print("{}", *it);
	}
	println("");
}
