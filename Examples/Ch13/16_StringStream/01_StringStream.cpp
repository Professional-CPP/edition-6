import std;

using namespace std;

int main()
{
	println("Enter tokens. "
		"Control+D (Unix) or Control+Z (Windows) followed by Enter to end.");

	ostringstream outStream;

	bool firstLoop{ true };
	while (cin) {
		string nextToken;
		print("Next token: ");
		cin >> nextToken;

		if (!cin || nextToken == "done") {
			break;
		}

		if (!firstLoop) {
			outStream << ", ";
		}
		outStream << '"' << nextToken << '"';
		firstLoop = false;
	}

	println("The end result is: {}", outStream.str());
}
