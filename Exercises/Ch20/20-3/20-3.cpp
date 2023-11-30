import std;

using namespace std;

string trim(string_view text)
{
	auto isNonWhitespace{ [](char c) { return !isspace(c); } };
	auto firstNonWhitespace{ ranges::find_if(text, isNonWhitespace) };
	auto lastNonWhitespace{ ranges::find_last_if(text, isNonWhitespace) };
    return { firstNonWhitespace, lastNonWhitespace.begin() + 1};
}

int main()
{
    println("'{}'", trim("   Hello World!   "));
    println("'{}'", trim("Hello World!   "));
	println("'{}'", trim("   Hello World!"));
	println("'{}'", trim("Hello World!"));
	println("'{}'", trim(" \t Hello World! \n"));
}
