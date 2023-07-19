import std;

using namespace std;
using namespace std::chrono;

int main()
{
	regex r{ "(\\d{4})-(\\d{2})-(\\d{2})" };
	while (true) {
		print("Enter a date (yyyy-mm-dd) (q=quit): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_match(str, m, r)) {
			println("  Parsed date, now validating...");
			year_month_day date{ year{ stoi(m[1]) },
				month{ stoul(m[2]) },
				day{ stoul(m[3]) } };
			println("    date is {}", (date.ok() ? "valid." : "not valid!"));
		} else {
			println("  Cannot parse date!");
		}
	}
}
