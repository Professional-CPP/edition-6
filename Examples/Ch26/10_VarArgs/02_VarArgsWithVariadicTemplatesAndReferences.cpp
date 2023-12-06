import std;

using namespace std;

void handleValue(int value) { println("Integer: {}", value); }
void handleValue(double value) { println("Double: {}", value); }
void handleValue(const string& value) { println("String: {}", value); }


void processValues()	// Base case to stop recursion
{
	// Nothing to do in this base case.
}

// Version using forwarding references
template<typename T1, typename... Tn>
void processValues(T1&& arg1, Tn&&... args)
{
	handleValue(forward<T1>(arg1));
	processValues(forward<Tn>(args)...);
}


int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
}
