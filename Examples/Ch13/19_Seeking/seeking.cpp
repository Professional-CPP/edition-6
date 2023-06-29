import std;

using namespace std;

int main()
{
	ofstream fout{ "test.out" };
	if (!fout) {
		println(cerr, "Error opening test.out for writing.");
		return 1;
	}

	// 1. Output the string "54321".
	fout << "54321";

	// 2. Verify that the marker is at position 5.
	streampos curPos{ fout.tellp() };
	if (curPos == 5) {
		println("Test passed: Currently at position 5.");
	} else {
		println("Test failed: Not at position 5!");
	}

	// 3. Move to position 2 in the output stream.
	fout.seekp(2, ios_base::beg);

	// 4. Output a 0 in position 2 and close the output stream.
	fout << 0;
	fout.close();

	// 5. Open an input stream on test.out.
	ifstream fin{ "test.out"};
	if (!fin) {
		println(cerr, "Error opening test.out for reading.");
		return 1;
	}

	// 6. Read the first token as an integer.
	int testVal;
	fin >> testVal;
	if (!fin) {
		println(cerr,  "Error reading from file.");
		return 1;
	}

	// 7. Confirm that the value is 54021.
	const int expected{ 54021 };
	if (testVal == expected) {
		println("Test passed: Value is {}.", expected);
	} else {
		println("Test failed: Value is not {} (it was {}).", expected, testVal);
	}
}
