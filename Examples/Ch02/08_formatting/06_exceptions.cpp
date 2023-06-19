import std;

using namespace std;

int main()
{
	try {
		vprint_unicode("An integer: {5}", make_format_args(42));
	} catch (const format_error& caught_exception) {
		println("{}", caught_exception.what()); // "Argument not found."
	}
}