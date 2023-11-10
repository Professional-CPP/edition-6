import std;

using namespace std;

vector<int> readIntegerFile(const string& filename)
{
	ifstream inputStream { filename };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw invalid_argument{ "Unable to open the file." };
	}

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// We did not reach the end-of-file.
		// This means that some error occurred while reading the file.
		// Throw an exception.
		throw runtime_error{ "Error reading the file." };
	}

	return integers;
}

[[noreturn]] void myTerminate()
{
	println(cerr, "Uncaught exception!");
	_Exit(1);
}

int main()
{
	set_terminate(myTerminate);

	const string filename{ "IntegerFile.txt" };
	vector<int> myInts{ readIntegerFile(filename) };
	println("{} ", myInts);
}
