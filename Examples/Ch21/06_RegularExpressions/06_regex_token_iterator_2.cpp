import std;

using namespace std;

int main()
{
	regex reg{ "^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$" };
	while (true) {
		print("Enter a date (year/month/day) (q=quit): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		vector indices{ 2, 3 };
		const sregex_token_iterator end;
		for (sregex_token_iterator iter{ cbegin(str), cend(str), reg, indices };
			iter != end; ++iter) {
			println("\"{}\"", iter->str());
		}
	}
}