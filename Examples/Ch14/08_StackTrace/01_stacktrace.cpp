import std;

using namespace std;

void handleStackTrace(const stacktrace& trace)
{
	println("  Stack trace information:");
	println("    There are {} frames in the stack trace.", trace.size());
	println("    Here are all the frames:");
	println("---------------------------------------------------------");
	println("{}", trace);
	// If the above statement doesn't work yet, you can use the following:
	//println("{}", to_string(trace));
	println("---------------------------------------------------------");
}

void C()
{
	println("Entered C().");
	handleStackTrace(stacktrace::current());
}

void B()
{
	println("Entered B().");
	C();
}

void A()
{
	println("Entered A().");
	B();
}

int main()
{
	A();
}
