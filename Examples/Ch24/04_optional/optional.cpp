import std;

using namespace std;

optional<int> Parse(const string& str)
{
	try {
		return stoi(str);
	} catch (...) {
		return {};
	}
}

int main()
{
	while (true) {
		print("Enter an integer (q to stop): ");
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		auto result{ Parse(str)
			.and_then([](int value) -> optional<int> { return value * 2; })
			.transform([](int value) { return to_string(value); })
			.or_else([] { return optional<string>{ "No Integer" }; }) };
		println("    > Result: {}", *result);
	}
}
