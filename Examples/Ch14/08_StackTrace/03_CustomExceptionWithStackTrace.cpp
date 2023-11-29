import std;

using namespace std;

class MyException : public exception
{
public:
	explicit MyException(string message,
		source_location location = source_location::current())
		: m_message{ move(message) }
		, m_location{ move(location) }
		, m_stackTrace{ stacktrace::current(1) } // 1 means skip top frame.
	{
	}

	const char* what() const noexcept override { return m_message.c_str(); }

	virtual const source_location& where() const noexcept { return m_location; }

	virtual const stacktrace& how() const noexcept { return m_stackTrace; }

private:
	string m_message;
	source_location m_location;
	stacktrace m_stackTrace;
};

void doSomething()
{
	throw MyException{ "Throwing MyException." };
}

int main()
{
	try {
		doSomething();
	} catch (const MyException& e) {
		// Print exception description + location where exception was raised.
		const auto& location{ e.where() };
		println(cerr, "Caught: '{}' at line {} in {}.",
			e.what(), location.line(), location.function_name());

		// Print the stack trace at the point where the exception was raised.
		println(cerr, "  Stack trace:");
		for (unsigned index{ 0 }; auto&& frame : e.how()) {
			const string& fileName{ frame.source_file() };
			println(cerr, "    {}> {}, {}({})", index++, frame.description(),
				(fileName.empty() ? "n/a" : fileName), frame.source_line());
		}
	}
}
