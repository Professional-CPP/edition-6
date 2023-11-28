module person_database;

import std;

using namespace std;

void Database::add(Person person)
{
	m_persons.push_back(move(person));
}

void Database::clear()
{
	m_persons.clear();
}

void Database::save(const string& filename) const
{
	ofstream outFile{ filename, ios_base::trunc };
	if (!outFile) {
		println(cerr, "Cannot open file: {}", filename);
		return;
	}

	for (const auto& person : m_persons) {
		// We need to support spaces in names.
		// So, to be able to read back names later in load(),
		// we simply quote all parts of the name.
		outFile << quoted(person.getFirstName())
			<< quoted(person.getLastName())
			<< quoted(person.getInitials()) << endl;
	}
}

void Database::load(const string& filename)
{
	ifstream inFile{ filename };
	if (!inFile) {
		println(cerr, "Cannot open file: {}", filename);
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
