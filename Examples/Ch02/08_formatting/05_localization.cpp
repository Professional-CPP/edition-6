import std;

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
	vprint_unicode(GetLocalizedFormat(language), make_format_args(1, 2));
	println("");
	language = Language::Dutch;
	vprint_unicode(GetLocalizedFormat(language), make_format_args(1, 2));

	// The following call using print() does not compile.
	//print(GetLocalizedFormat(language), 1, 2);
}