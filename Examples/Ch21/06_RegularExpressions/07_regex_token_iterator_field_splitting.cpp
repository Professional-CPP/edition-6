import std;

using namespace std;

int main()
{
	regex reg{ R"(\s*[,;]\s*)" };
	while (true) {
		print("Enter a string to split on ',' and ';' (q=quit): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		
		// Iterate over the tokens.
		const sregex_token_iterator end;
		for (sregex_token_iterator iter{ cbegin(str), cend(str), reg, -1 };
			iter != end; ++iter) {
			print("\"{}\", ", iter->str());
		}
		println("");

		// Store all tokens in a vector.
		vector<string> tokens {
			sregex_token_iterator { cbegin(str), cend(str), reg, -1 },
			sregex_token_iterator {} };
		// Print the contents of the tokens vector.
		println("{:n}", tokens);
	}
}