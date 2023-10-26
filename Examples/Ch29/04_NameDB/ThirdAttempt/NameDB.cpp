module name_db;

import std;

using namespace std;

// Reads the names from the file and populates the database.
// The database is a map associating names with their frequency.
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
		m_names[name] += 1;
	}
}

// Returns the rank of the name.
// First looks up the name to obtain the number of babies with that name.
// Then iterates through all the names, counting all the names with a higher
// count than the specified name. Returns that count as the rank.
int NameDB::getNameRank(const string& name) const
{
	int num{ getAbsoluteNumber(name) };

	// Check if we found the name.
	if (num == -1) {
		return -1;
	}

	// Now count all the names in the map that have 
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
	auto res{ m_names.find(name) };
	if (res != end(m_names)) {
		return res->second;
	}

	return -1;
}
