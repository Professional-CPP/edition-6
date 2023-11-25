import std;

using namespace std;

// The parameters are const references to avoid unnecessary copying.
string replace(const string& haystack, const string& needle, const string& replacement)
{
	// Make a copy of the haystack.
	string result{ haystack };

	// Find all needles and replace them with the replacement string.
	auto position{ result.find(needle) };
	while (position != string::npos) {
		result.replace(position, needle.length(), replacement);
		position = result.find(needle, position + replacement.size());
	}

	return result;
}

int main()
{
	// Ask for the source string (= haystack).
	string haystack;
	print("Enter source string: ");
	getline(cin, haystack);

	// Ask for the string to find (= needle).
	string needle;
	print("Enter string to find: ");
	getline(cin, needle);

	// Ask for the replacement string.
	string replacement;
	print("Enter replacement string: ");
	getline(cin, replacement);

	// Call the replace function.
	string result{ replace(haystack, needle, replacement) };

	// Print out all the strings for verification.
	println("Haystack: {}", haystack);
	println("Needle: {}", needle);
	println("Replacement: {}", replacement);
	println("Result: {}", result);
}
