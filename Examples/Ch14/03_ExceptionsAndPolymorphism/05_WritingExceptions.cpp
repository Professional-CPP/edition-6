import std;

using namespace std;

class FileError : public exception
{
public:
	explicit FileError(string filename) : m_filename{ move(filename) } {}
	const char* what() const noexcept override { return m_message.c_str(); }
	virtual const string& getFilename() const noexcept { return m_filename; }

protected:
	virtual void setMessage(string message) { m_message = move(message); }

private:
	string m_filename;
	string m_message;
};



class FileOpenError : public FileError
{
public:
	explicit FileOpenError(string filename) : FileError{ move(filename) }
	{
		setMessage(format("Unable to open {}.", getFilename()));
	}
};



class FileReadError : public FileError
{
public:
	explicit FileReadError(string filename, size_t lineNumber)
		: FileError{ move(filename) }, m_lineNumber{ lineNumber }
	{
		setMessage(format("Error reading {}, line {}.", getFilename(), lineNumber));
	}

	virtual size_t getLineNumber() const noexcept { return m_lineNumber; }

private:
	size_t m_lineNumber{ 0 };
};



vector<int> readIntegerFile(const string& filename)
{
	ifstream inputStream { filename };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw FileOpenError{ filename };
	}

	vector<int> integers;
	size_t lineNumber{ 0 };
	while (!inputStream.eof()) {
		// Read one line from the file.
		string line;
		getline(inputStream, line);
		++lineNumber;

		// Create a string stream out of the line.
		istringstream lineStream { line };

		// Read the integers one-by-one and add them to the vector.
		int temp;
		while (lineStream >> temp) {
			integers.push_back(temp);
		}

		if (!lineStream.eof()) {
			// We did not reach the end of the string stream.
			// This means that some error occurred while reading this line.
			// Throw an exception.
			throw FileReadError{ filename, lineNumber };
		}
	}

	return integers;
}

int main()
{
	const string filename{ "IntegerFile.txt" };
	vector<int> myInts;

	try {
		myInts = readIntegerFile(filename);
	} catch (const FileError& e) {
		println(cerr, "{}", e.what());
		return 1;
	}

	println("{} ", myInts);
}
