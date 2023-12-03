import std;

using namespace std;

int main()
{
	ofstream outputFile{ "FileWrite.out" };
	if (outputFile.fail()) {
		println(cerr, "Unable to open file for writing.");
		return 1;
	}
	outputFile << "Hello!" << endl;
	outputFile.close();

	ofstream appendFile{ "FileWrite.out", ios_base::app };
	if (appendFile.fail()) {
		println(cerr, "Unable to open file for appending.");
		return 2;
	}
	appendFile << "World!" << endl;
}
