import std;

using namespace std;
using namespace std::filesystem;

int main()
{
	path myPath{ "c:/windows/win.ini" };
	directory_entry dirEntry{ myPath };
	if (dirEntry.exists() && dirEntry.is_regular_file()) {
		println("File size: {}", dirEntry.file_size());
	}
}
