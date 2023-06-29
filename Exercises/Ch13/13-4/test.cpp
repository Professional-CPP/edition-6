import person;
import person_database;
import std;

using namespace std;

int main()
{
	// Fill a database.
	Database db;
	db.add(Person{ "John", "Doe" });
	db.add(Person{ "Marc", "Gregoire", "Mg" });
	db.add(Person{ "Peter", "Van Weert", "PVW" });

	// Output all persons in the database to standard output.
	println("Initial database contents:");
	db.outputAll(cout);

	// Save the database to files.
	db.save("D:\\Temp\\persons");

	// Clear the database.
	db.clear();
	println("\nDatabase contents after clearing:");
	db.outputAll(cout);
	
	// Load database from files.
	println("\nLoading database from files...");
	db.load("D:\\Temp\\persons");
	println("\nDatabase contents after loading from files:");
	db.outputAll(cout);
}
