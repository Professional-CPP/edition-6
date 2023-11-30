import std;

using namespace std;

int main()
{
	const string str{ "<body><h1>Header</h1><p>Some text</p></body>" };
	regex r{ "<h1>(.*)</h1><p>(.*)</p>" };

	const string replacement{ "H1=$1 and P=$2" };
	string result{ regex_replace(str, r, replacement, regex_constants::format_no_copy) };
	
	println("Original string: '{}'", str);
	println("New string     : '{}'", result);
}
