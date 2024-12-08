#include <print>
#include <format>
#include <string_view>
#include <iostream>

using namespace std;

enum class Language { English, Dutch };

string_view GetLocalizedFormat(Language language)
{
	switch (language) {
	case Language::English:
		return "Numbers: {0} and {1}.";
	case Language::Dutch:
		return "Getallen: {0} en {1}.";
	}
}

int main()
{
	Language language{ Language::English };
	int number1 = 1;
	int number2 = 2;
	vprint_unicode(cout, GetLocalizedFormat(language), make_format_args(number1, number2));
	println("");
	language = Language::Dutch;
	vprint_unicode(cout, GetLocalizedFormat(language), make_format_args(number1, number2));

	// The following call using print() does not compile.
	//print(GetLocalizedFormat(language), 1, 2);
}