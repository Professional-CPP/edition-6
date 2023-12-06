import std;

using namespace std;

void handleValue(int value) { println("Integer: {}", value); }
void handleValue(double value) { println("Double: {}", value); }
void handleValue(const string& value) { println("String: {}", value); }


void processValues()	// Base case to stop recursion
{
	// Nothing to do in this base case.
}

// Version using pass-by-value
template<typename T1, typename... Tn>
void processValues(const T1& arg1, const Tn&... args)
{
	handleValue(arg1);
	processValues(args...);
}


int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
}
