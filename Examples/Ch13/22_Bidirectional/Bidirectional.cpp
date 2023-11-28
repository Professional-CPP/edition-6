import std;

using namespace std;

// Returns false on error
bool changeNumberForID(const string& filename, int id, string_view newNumber);

int main()
{
	changeNumberForID("data.txt", 263, "415-555-3333");
}

bool changeNumberForID(const string& filename, int id, string_view newNumber)
{
	fstream ioData{ filename };
	if (!ioData) {
		println(cerr, "Error while opening file {}.", filename);
		return false;
	}

	// Loop until the end of file
	while (ioData) {
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData) {
			break;
		}

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << newNumber;
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
	}
	return true;
}