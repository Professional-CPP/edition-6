import std;

using namespace std;

void close(FILE* filePtr)
{
	if (filePtr == nullptr) { return; }
	fclose(filePtr);
	println("File closed.");
}

int main()
{
#if defined(_MSC_VER)
	// Disable the following Microsoft Visual C++ warning for this example:
	// C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead.
	#pragma warning( disable : 4996)
#endif

	FILE* f{ fopen("data.txt", "w") };
	shared_ptr<FILE> filePtr{ f, close };
	if (filePtr == nullptr) {
		println(cerr, "Error opening file.");
	} else {
		println("File opened.");
		// Use filePtr
	}
}
