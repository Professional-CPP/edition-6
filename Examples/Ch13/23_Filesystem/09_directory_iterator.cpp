import std;

using namespace std;
using namespace std::filesystem;

void printDirectoryStructure(const path& p, unsigned level = 0)
{
	if (!exists(p)) {
		return;
	}

	const string spacer(level * 2, ' ');

	if (is_regular_file(p)) {
		println("{}File: {} ({} bytes)", spacer, p.string(), file_size(p));
	} else if (is_directory(p)) {
		println("{}Dir: {}", spacer, p.string());
		for (auto& entry : directory_iterator{ p }) {
			printDirectoryStructure(entry, level + 1);
		}
	}
}

int main()
{
	path p{ R"(D:\Foo\Bar)" };
	printDirectoryStructure(p);
}
