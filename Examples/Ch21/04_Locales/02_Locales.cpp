import std;

using namespace std;

int main()
{
	cout.imbue(locale{ "" });
	cout << "User's locale: " << 32767 << endl;

	cout.imbue(locale{ "C" });
	cout << "C locale: " << 32767 << endl;

	cout.imbue(locale{ "en-US" }); // "en_US" for POSIX
	cout << "en-US locale: " << 32767 << endl;
	
	locale::global(locale{ "en-US" }); // "en_US" for POSIX
	println("println(): {}", 32767);
	println("println() using global locale: {:L}", 32767);
	cout << format(locale{ "en-US" }, "format() with en-US locale: {:L}", 32767);
}