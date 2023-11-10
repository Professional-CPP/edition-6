import std;

using namespace std;

using Parameter = tuple<string, variant<bool, int, string>>;

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

class CommandLineParameterVisitor
{
public:
	explicit CommandLineParameterVisitor(string parameterName) : m_parameterName{ move(parameterName) } {}

	void operator()(bool value) { println("Boolean: {} -> {}", m_parameterName, value); }
	void operator()(int value) { println("Integer: {} -> {}", m_parameterName, value); }
	void operator()(string value) { println("String: {} -> {}", m_parameterName, value); }

private:
	string m_parameterName;
}; 

int main(int argc, char** argv)
{
	for (int i{ 0 }; i < argc; ++i) {
		try {
			auto parameter{ parseParameter(argv[i]) };
			CommandLineParameterVisitor visitor{ get<string>(parameter) };
			visit(visitor, get<1>(parameter));
		} catch (const invalid_argument&) {
			// Could not parse parameter, ignore it.
		}
	}
}
