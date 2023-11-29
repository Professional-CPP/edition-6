import std;

using namespace std;

vector<int> readIntegerFile(const string& filename)
{
	ifstream inputStream { filename };

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

int main()
{
	const string filename{ "IntegerFile.txt" };
	vector<int> myInts{ readIntegerFile(filename) };
	println("{} ", myInts);
}
