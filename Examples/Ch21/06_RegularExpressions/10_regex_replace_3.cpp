import std;

using namespace std;

int main()
{
	regex reg{ "([\\w]+)" };
	const string replacement{ "$1\n" };
	while (true) {
		print("Enter a string to split over multiple lines (q=quit): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		
		println("{}", regex_replace(str, reg, replacement,
			regex_constants::format_no_copy));
	}
}
