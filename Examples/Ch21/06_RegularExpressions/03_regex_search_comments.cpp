import std;

using namespace std;

int main()
{
	regex r{ "//\\s*(.+)$" };
	while (true) {
		print("Enter a string with optional code comments (q=quit):\n> ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_search(str, m, r)) {
			println("  Found comment '{}'", m[1].str());
		} else {
			println("  No comment found!");
		}
	}
}
