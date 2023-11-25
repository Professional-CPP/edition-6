import std;

using namespace std;

int main()
{
	// Escaped output
	println("|{:?}|", "Hello\tWorld!\n");  // |Hello\tWorld!\n|
	println("|{:?}|", "\"");               // |"\""|
	println("|{:?}|", '\'');               // |'\''|
	println("|{:?}|", '"');                // |'"'|
}
