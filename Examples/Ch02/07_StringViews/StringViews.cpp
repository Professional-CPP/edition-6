import std;

using namespace std;

string extractExtension(string_view filename)
{
	// Return a copy of the extension.
	return string{ filename.substr(filename.rfind('.')) };
}

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
	}

	{
		// Concatenation with string_view.
		string str{ "Hello" };
		string_view sv{ " world" };
		//auto result{ str + sv };  // Error, does not compile!
		auto result1{ str + string { sv } };

		string result2{ str };
		result2.append(sv.data(), sv.size());
		
		println("{}\n{}", result1, result2);
	}

	{
		// Using the standard user-defined literal sv.
		auto sv{ "My string_view"sv };
	}
}
