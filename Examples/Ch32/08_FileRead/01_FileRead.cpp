import std;

using namespace std;

int main()
{
	ifstream inputFile{ "FileWrite.out" };
	if (inputFile.fail()) {
		println(cerr, "Unable to open file for reading.");
		return 1;
	}

	string nextToken;
	while (inputFile >> nextToken) {
		println("Token: {}", nextToken);
	}
}
