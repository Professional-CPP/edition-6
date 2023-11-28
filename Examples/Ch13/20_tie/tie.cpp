import std;

using namespace std;

int main()
{
	ifstream inFile{ "input.txt" };  // Note: input.txt must exist.
	ofstream outFile{ "output.txt" };
	// Set up a link between inFile and outFile.
	inFile.tie(&outFile);
	// Output some text to outFile. Normally, this would
	// not flush because std::endl is not send.
	outFile << "Hello there!";
	// outFile has NOT been flushed.
	// Read some text from inFile. This will trigger flush() on outFile.
	string nextToken;
	inFile >> nextToken;
	// outFile HAS been flushed.
}
