import std;

using namespace std;

int main()
{
	ifstream inputFile{ "FileWrite.out" };
	if (inputFile.fail()) {
		println(cerr, "Unable to open file for reading.");
		return 1;
	}

	string fileContents{
		istreambuf_iterator<char> { inputFile },
		istreambuf_iterator<char> { }
	};
	println("{}", fileContents);
}
