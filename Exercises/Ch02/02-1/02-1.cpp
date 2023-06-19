import std;

using namespace std;

int main()
{
	// Ask a first string.
	print("First string: ");
	string s1;
	getline(cin, s1);

	// Ask a second string.
	print("Second string: ");
	string s2;
	getline(cin, s2);

	// Print the strings in alphabetical order using <=>.
	if (is_lt(s1 <=> s2)) {
		println("{}\n{}", s1, s2);
	} else {
		println("{}\n{}", s2, s1);
	}
}
