export module person_database;

import person;
import std;

export class Database
{
public:
	// Adds the given person to the database.
	void add(Person person);

	// Removes all persons from the database.
	void clear();

	// Saves all persons in the database to separate files in the given folder.
	void save(const std::filesystem::path& folder) const;

	// Loads all persons from the given folder and stores them in the database.
	void load(const std::filesystem::path& folder);

	// Outputs all persons to the given stream.
	void outputAll(std::ostream& output) const;

private:
	std::vector<Person> m_persons;

	// Helper member function to load a single file.
	void loadFile(const std::filesystem::path& file);
};
