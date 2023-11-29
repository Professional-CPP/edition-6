import std;

using namespace std;

class MyException : public exception
{
public:
	explicit MyException(string message) : m_message{ move(message) } {}
	const char* what() const noexcept override { return m_message.c_str(); }

private:
	string m_message;
};


void doSomething()
{
	try {
		throw runtime_error{ "A runtime_error exception" };
	} catch (const runtime_error& /*e*/) {
		println("doSomething() caught a runtime_error");
		println("doSomething() throwing MyException");
		throw_with_nested(MyException{ "MyException with nested runtime_error" });
	}
}

int main()
{
	try {
		doSomething();
	} catch (const MyException& e) {
		println("main() caught MyException: {}", e.what());

/*		const auto* nested{dynamic_cast<const nested_exception*>(&e)};
		if (nested) {
			try {
				nested->rethrow_nested();
			} catch (const runtime_error& e) {
				// Handle nested exception.
				println("  Nested exception: {}", e.what());
			}
		}
*/
		try {
			rethrow_if_nested(e);
		} catch (const runtime_error& e) {
			// Handle nested exception.
			println("  Nested exception: {}", e.what());
		}
	}
}
