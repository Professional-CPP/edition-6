import std;

using namespace std;

auto multiply(const auto& a, const auto& b)
{
	// As a first step, since this is an abbreviated function template,
	// we don't have direct access to the types. However, we can use
	// decltype(a) and decltype(b) to query the types of a and b.
	// 
	// In a second step, for analyzing the types, we need to strip any
	// const, volatile, and reference qualifiers from the types. For this
	// we use the std::remove_cvref type trait.
	using T1 = remove_cvref_t<decltype(a)>;
	using T2 = remove_cvref_t<decltype(b)>;

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
