import std;

using namespace std;

void handleStackTrace(const stacktrace& trace)
{
	println("  Stack trace information:");
	println("    There are {} frames in the stack trace.", trace.size());
	println("    Here are the descriptions of all the frames:");
	for (unsigned index{ 0 }; auto&& frame : trace) {
		println("      {} -> {}", index++, frame.description());
	}
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
