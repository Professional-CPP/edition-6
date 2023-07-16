import std;

using namespace std;

string trim(string_view text)
{
	auto isNonWhitespace{ [](char c) { return !isspace(c); } };

    auto firstNonWhitespace{
        find_if(begin(text), end(text), isNonWhitespace) };

	// There is no unconstrained variant of ranges::find_last_if().
	// Instead, we used find_if() in combination with reverse iterators.
    // Remember from Chapter 17, to obtain the underlying iterator from a
    // reverse_iterator, you need to call the base() method on the reverse_iterator.
    auto onePassedLastNonWhitespace{
        find_if(rbegin(text), rend(text), isNonWhitespace).base() };
    
    return { firstNonWhitespace, onePassedLastNonWhitespace };
}

int main()
{
	println("'{}'", trim("   Hello World!   "));
	println("'{}'", trim("Hello World!   "));
	println("'{}'", trim("   Hello World!"));
	println("'{}'", trim("Hello World!"));
	println("'{}'", trim(" \t Hello World! \n"));
}
