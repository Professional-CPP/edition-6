#include <print>
#include <format>
#include <iostream>

using namespace std;

int main()
{
	try {
		int number{ 42 };
		vprint_unicode(cout, "An integer: {5}", make_format_args(number));
	} catch (const format_error& caught_exception) {
		println("{}", caught_exception.what()); // "Argument not found."
	}
}