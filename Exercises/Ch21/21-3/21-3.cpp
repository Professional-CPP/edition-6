import std;

using namespace std;

int main()
{
	regex r{ "^(.*?)//.*$" };
	const string replacement{ "$1" };
	while (true) {
		println("Enter a source code snippet, terminated with @:");
		string str;
		if (!getline(cin, str, '@')) {
			break;
		}

		println("{}", regex_replace(str, r, replacement));
	}
}