import std;

using namespace std;

template <typename T>
void processHelper(const T& t, true_type)
{
	println("{} is an integral type.", t);
}

template <typename T>
void processHelper(const T& t, false_type)
{
	println("{} is a non-integral type.", t);
}

template <typename T>
void process(const T& t)
{
	processHelper(t, is_integral<T>{});
}

int main()
{
	process(123);
	process(2.2);
	process("Test"s);
}
