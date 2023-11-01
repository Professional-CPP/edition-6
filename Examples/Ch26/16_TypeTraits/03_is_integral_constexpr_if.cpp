import std;

using namespace std;

template<typename T>
void process(const T& t)
{
	if constexpr (is_integral_v<T>) {
		println("{} is an integral type.", t);
	} else {
		println("{} is a non-integral type.", t);
	}
}

int main()
{
	process(123);
	process(2.2);
	process("Test"s);
}
