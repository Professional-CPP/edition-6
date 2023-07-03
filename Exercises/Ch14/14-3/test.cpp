import person;
import person_database;
import std;

using namespace std;

int main()
{
	try {
		// Fill a database.
		Database db;
		db.add(Person{ "John", "Doe" });
		db.add(Person{ "Marc", "Gregoire", "Mg" });
		db.add(Person{ "Peter", "Van Weert", "PVW" });

		// Output all persons in the database to standard output.
		println("Initial database contents:");
		db.outputAll(cout);

		// Save the database to a file.
		db.save("person.db");

		// Clear the database.
		db.clear();
		println("\nDatabase contents after clearing:");
		db.outputAll(cout);

		// Load database from file.
		println("\nLoading database from file...");
		db.load("person.db");
		println("\nDatabase contents after loading from file:");
		db.outputAll(cout);
	} catch (const exception& caughtException) {
		println(cerr, "{}", caughtException.what());
	}
}
