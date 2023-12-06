import std;

using namespace std;

template <typename T1, typename T2>
auto multiply(const T1& a, const T2& b)
{
	if constexpr (is_arithmetic_v<T1> && is_arithmetic_v<T2>) {
		return a * b;
	} else {
		throw invalid_argument{
			format("Cannot multiply types '{}' and '{}' as they are not arithmetic.",
				typeid(T1).name(), typeid(T2).name()) };
		return 0;
	}
}

int main()
{
	try {
		println("{}", multiply(2, 3));
		println("{}", multiply(2, 3.3));
		println("{}", multiply("Test", 3.2));
	} catch (const exception& caughtException) {
		println("Caught: {}", caughtException.what());
	}
}
