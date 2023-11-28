module person_database;

import std;

using namespace std;
using namespace std::filesystem;

void Database::add(Person person)
{
	m_persons.push_back(move(person));
}

void Database::clear()
{
	m_persons.clear();
}

void Database::save(const path& folder) const
{
	for (const auto& person : m_persons) {
		// Construct the name of the target file.
		path filename{ folder };
		filename /= format("{}_{}", person.getFirstName(), person.getLastName());
		filename += ".person";

		// Open the file for writing.
		ofstream outFile{ filename, ios_base::trunc };
		if (!outFile) {
			println(cerr, "Cannot open file: {}", filename.string());
			return;
		}

		// We need to support spaces in names.
		// So, to be able to read back names later in load(),
		// we simply quote all parts of the name.
		outFile << quoted(person.getFirstName())
			<< quoted(person.getLastName())
			<< quoted(person.getInitials()) << endl;
	}
}

void Database::load(const path& folder)
{
	// Iterate over all the files in the given folder.
	directory_iterator begin{ folder };
	directory_iterator end{ };
	for (auto iter{ begin }; iter != end; ++iter) {
		auto& entry{ *iter };

		// Skip if there is no extension, or it is not .person
		if (!entry.path().has_extension() ||
			entry.path().extension() != ".person") {
			continue;
		}

		// Parse the file.
		loadFile(entry);
	}
}

void Database::loadFile(const std::filesystem::path& file)
{
	ifstream inFile{ file };
	if (!inFile) {
		println(cerr, "Cannot open file: {}", file.string());
		return;
	}

	while (inFile) {
		// Read line by line, so we can skip empty lines.
		// The last line in the file is empty, for example.
		string line;
		getline(inFile, line);
		if (line.empty()) { // Skip empty lines
			continue;
		}

		// Make a string stream and parse it.
		istringstream inLine{ line };
		string firstName, lastName, initials;
		inLine >> quoted(firstName) >> quoted(lastName) >> quoted(initials);
		if (inLine.bad()) {
			println(cerr, "Error reading person. Ignoring.");
			continue;
		}

		// Create a person and add it to the database.
		m_persons.push_back(Person{ move(firstName), move(lastName), move(initials) });
	}
}

void Database::outputAll(ostream& output) const
{
	for (const auto& person : m_persons) {
		person.output(output);
	}
}
