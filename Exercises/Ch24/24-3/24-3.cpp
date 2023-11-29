import std;

using namespace std;

using Parameter = pair<string, variant<bool, int, string>>;

Parameter parseParameter(const char* parameter)
{
	regex r{ "(.*)=(.*)" };
	if (cmatch m; regex_match(parameter, m, r)) {
		const auto& name{ m[1].str() };
		const auto& value{ m[2].str() };

		// Try to parse as Boolean.
		if (value == "true") { return { name, true }; }
		else if (value == "false") { return { name, false }; }

		// Try to parse as integer.
		try {
			int parsedInteger{ stoi(value) };
			return { name, parsedInteger };
		} catch (const exception&) {
			// Could not parse as integer.
		}

		// Just interpret as string.
		return { name, value };
	}
	throw invalid_argument{ "Cannot parse parameter." };
}

int main(int argc, char** argv)
{
	for (int i{ 0 }; i < argc; ++i) {
		try {
			auto parameter{ parseParameter(argv[i]) };
			if (holds_alternative<bool>(parameter.second)) {
				println("Boolean: {} -> {}",
					parameter.first,
					get<bool>(parameter.second));
			} else if (holds_alternative<int>(parameter.second)) {
				println("Integer: {} -> {}",
					parameter.first,
					get<int>(parameter.second));
			} else if (holds_alternative<string>(parameter.second)) {
				println("String: {} -> {}",
					parameter.first,
					get<string>(parameter.second));
			}
		} catch (const invalid_argument&) {
			// Could not parse parameter, ignore it.
		}
	}
}
