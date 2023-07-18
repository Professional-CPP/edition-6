import std;

using namespace std;

int main()
{
	regex r{ "\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])" };
	while (true) {
		print("Enter a date (year/month/day) (q=quit): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (regex_match(str, r)) {
			println("  Valid date.");
		} else {
			println("  Invalid date!");
		}
	}
}
