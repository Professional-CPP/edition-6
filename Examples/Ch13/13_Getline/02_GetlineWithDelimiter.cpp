import std;

using namespace std;

int main()
{
	print("Enter multiple lines of text. "
		"Use an @ character to signal the end of the text.\n> ");

	string myString;
	getline(cin, myString, '@');

	println("Read text: \"{}\"", myString);
}
