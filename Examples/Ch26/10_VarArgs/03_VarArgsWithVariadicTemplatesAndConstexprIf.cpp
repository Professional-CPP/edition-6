import std;

using namespace std;

void handleValue(int value) { println("Integer: {}", value); }
void handleValue(double value) { println("Double: {}", value); }
void handleValue(const string& value) { println("String: {}", value); }

template<typename T1, typename... Tn>
void processValues(T1&& arg1, Tn&&... args)
{
	handleValue(forward<T1>(arg1));
	if constexpr (sizeof...(args) > 0) {
		processValues(forward<Tn>(args)...);
	}
}

int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
}
