import std;

using namespace std;

int main()
{
	const char8_t* s1{ u8R"(Raw UTF-8 string literal)" };
	const wchar_t* s2{ LR"(Raw wide string literal)" };
	const char16_t* s3{ uR"(Raw UTF-16 string literal)" };
	const char32_t* s4{ UR"(Raw UTF-32 string literal)" };

	wcout << s2 << endl;
	// Can't stream s1, s3, and s4, because streams don't support char8_t, char16_t, and char32_t.

	const char8_t* formula1{ u8"\x3C0 r\xB2" };
	const char8_t* formula2{ u8"\u03C0 r\u00B2" };
	const char8_t* formula3{ u8"\N{GREEK SMALL LETTER PI} r\N{SUPERSCRIPT TWO}" };

	// C++23
	const char hello[]{ u8"こんにちは世界" };
	println("{}", hello);

	{
		// The same 3 formula from before, but this time using
		// const char[] instead of const char8_t*.
		const char formula1[]{ u8"\x3C0 r\xB2" };
		const char formula2[]{ u8"\u03C0 r\u00B2" };
		const char formula3[]{ u8"\N{GREEK SMALL LETTER PI} r\N{SUPERSCRIPT TWO}" };

		println("{}", formula1);
		println("{}", formula2);
		println("{}", formula3);
	}
}
