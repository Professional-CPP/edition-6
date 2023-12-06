import std;

using namespace std;

void handleValue(int value) { println("Integer: {}", value); }
void handleValue(double value) { println("Double: {}", value); }
void handleValue(const string& value) { println("String: {}", value); }

template<typename... Tn>
void processValues(Tn&&... args)
{
	(handleValue(forward<Tn>(args)), ...);
}

int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
}