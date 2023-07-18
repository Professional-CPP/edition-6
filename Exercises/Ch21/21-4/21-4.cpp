import std;

using namespace std;

int main()
{
	regex r{ "(?=(?:.*\\d){2})(?=.*[[:lower:]])(?=.*[[:upper:]])(?=.*[[:punct:]]).{8,}" };
	while (true) {
		print("Enter a password (q=quit): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (regex_match(str, r)) {
			println("  Valid password.");
		} else {
			println("  Invalid password!");
		}
	}
}