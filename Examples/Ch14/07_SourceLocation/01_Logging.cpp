import std;

using namespace std;

void logMessage(string_view message,
	const source_location& location = source_location::current())
{
	println("{}({}): {}: {}", location.file_name(),
		location.line(), location.function_name(), message);
}

void foo()
{
	logMessage("Starting execution of foo().");
}

int main()
{
	foo();
}
