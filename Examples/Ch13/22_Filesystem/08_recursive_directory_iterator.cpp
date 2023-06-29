import std;

using namespace std;
using namespace std::filesystem;

void printDirectoryStructure(const path& p)
{
	if (!exists(p)) {
		return;
	}

	recursive_directory_iterator begin{ p };
	recursive_directory_iterator end{};
	for (auto iter{ begin }; iter != end; ++iter) {
		const string spacer(iter.depth() * 2, ' ');

		auto& entry{ *iter }; // Dereference iter to access directory_entry.

		if (is_regular_file(entry)) {
			println("{}File: {} ({} bytes)",
				spacer, entry.path().string(), file_size(entry));
		} else if (is_directory(entry)) {
			println("{}Dir: {}", spacer, entry.path().string());
		}
	}
}

int main()
{
	path p{ R"(D:\Foo\Bar)" };
	printDirectoryStructure(p);
}
