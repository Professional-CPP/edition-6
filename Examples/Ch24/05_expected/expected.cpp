import std;

using namespace std;

expected<int, string> parseInteger(const string& str)
{
	try {
		return stoi(str);
	} catch (const invalid_argument& e) {
		return unexpected{ e.what() };
	} catch (const out_of_range& e) {
		return unexpected{ e.what() };
	}
}


int main()
{
	auto result1{ parseInteger("123456789") };
	if (result1.has_value()) {
		println("result1 = {}", result1.value());
	}
	if (result1) {
		println("result1 = {}", *result1);
	}
	println("result1 = {}", result1.value_or(0));


	auto result2{ parseInteger("123456789123456") };
	if (!result2) {
		println("result2 contains an error: {}", result2.error());
	}


	auto result3{ parseInteger("abc") };
	if (!result3) {
		println("result3 contains an error: {}", result3.error());
	}


	auto transformedResult{ parseInteger("123456789")
		.and_then([](int value) -> expected<int, string> { return value * 2; }) };
	if (transformedResult) {
		println("transformedResult = {}", *transformedResult);
	}
}
