import std;

using namespace std;

int main(int argc, char* argv[])
{
	ofstream outFile{ "test.txt", ios_base::trunc };
	if (!outFile.good()) {
		println(cerr, "Error while opening output file!");
		return -1;
	}
	outFile << "There were " << argc << " arguments to this program." << endl;
	outFile << "They are: " << endl;
	for (int i{ 0 }; i < argc; i++) {
		outFile << argv[i] << endl;
	}
}
