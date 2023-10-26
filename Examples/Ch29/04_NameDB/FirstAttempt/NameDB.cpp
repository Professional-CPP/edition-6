module name_db;

import std;

using namespace std;

// Reads the names from the file and populates the database.
// The database is a vector of name/count pairs, storing the
// number of times each name shows up in the raw data.
NameDB::NameDB(const string& nameFile)
{
	// Open the file and check for errors.
	ifstream inputFile{ nameFile };
	if (!inputFile) {
		throw invalid_argument{ "Unable to open file" };
	}

	// Read the names one at a time.
	string name;
	while (inputFile >> name) {
		// Look up the name in the database so far.
		if (nameExists(name)) {
			// If the name exists in the database, just increment the count.
			incrementNameCount(name);
		} else {
			// If the name doesn't yet exist, add it with a count of 1.
			addNewName(name);
		}
	}
}

// Returns true if the name exists in the database, false otherwise.
bool NameDB::nameExists(const string& name) const
{
	// Iterate through the vector of names looking for the name.
	for (auto& entry : m_names) {
		if (entry.first == name) {
			return true;
		}
	}
	return false;
}

// Precondition: name exists in the vector of names.
// Postcondition: the count associated with name is incremented.
void NameDB::incrementNameCount(const string& name)
{
	for (auto& entry : m_names) {
		if (entry.first == name) {
			entry.second += 1;
			return;
		}
	}
}

// Adds a new name to the database.
void NameDB::addNewName(const string& name)
{
	m_names.emplace_back(name, 1);
}

// Returns the rank of the name.
// First looks up the name to obtain the number of babies with that name.
// Then iterates through all the names, counting all the names with a higher
// count than the specified name. Returns that count as the rank.
int NameDB::getNameRank(const string& name) const
{
	// Make use of the getAbsoluteNumber() member function.
	int num{ getAbsoluteNumber(name) };

	// Check if we found the name.
	if (num == -1) {
		return -1;
	}

	// Now count all the names in the vector that have a
	// count higher than this one. If no name has a higher count,
	// this name is rank number 1. Every name with a higher count
	// decreases the rank of this name by 1.
	int rank{ 1 };
	for (auto& entry : m_names) {
		if (entry.second > num) {
			++rank;
		}
	}

	return rank;
}

// Returns the count associated with the given name.
int NameDB::getAbsoluteNumber(const string& name) const
{
	for (auto& entry : m_names) {
		if (entry.first == name) {
			return entry.second;
		}
	}
	return -1;
}
