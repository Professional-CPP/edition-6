import std;

using namespace std;

string_view extractExtension(string_view filename)
{
	return filename.substr(filename.rfind('.'));
}

void handleExtension(const string& extension) { /* ... */ }

int main()
{
	{
		// C++ std::string.
		string filename{ R"(c:\temp\my file.ext)" };
		println("C++ string: {}", extractExtension(filename));

		// C-style string.
		const char* cString{ R"(c:\temp\my file.ext)" };
		println("C string: {}", extractExtension(cString));

		// String literal.
		println("Literal: {}", extractExtension(R"(c:\temp\my file.ext)"));

		// Raw string buffer with given length.
		const char* raw{ "test.ext" };
		size_t length{ 8 };
		println("Raw: {}", extractExtension({ raw, length }));
		println("Raw: {}", extractExtension(string_view{ raw, length }));

		// Assigning the result to a std::string.
		string extension{ extractExtension(filename).data() };

		//handleExtension(extractExtension("my file.ext")); // Error, does not compile!

		handleExtension(extractExtension("my file.ext").data());    // data() method
		handleExtension(string{ extractExtension("my file.ext") }); // explicit ctor
	}

	{
		// Concatenation with string_view.
		string str{ "Hello" };
		string_view sv{ " world" };
		//auto result{ str + sv };  // Error, does not compile!
		auto result1{ str + sv.data() };
		string result2{ str };
		result2.append(sv.data(), sv.size());
		println("{}\n{}", result1, result2);
	}

	{
		// Using the standard user-defined literal sv.
		auto sv{ "My string_view"sv };
	}
}
