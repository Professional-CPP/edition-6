import std;
import database;
import employee;

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int main()
{
	Database employeeDB;

	bool done{ false };
	while (!done) {
		int selection{ displayMenu() };
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			println(cerr, "Unknown command.");
			break;
		}
	}
}

int displayMenu()
{
	// Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

	int selection;

	println("");
	println("Employee Database");
	println("-----------------");
	println("1) Hire a new employee");
	println("2) Fire an employee");
	println("3) Promote an employee");
	println("4) List all employees");
	println("5) List all current employees");
	println("6) List all former employees");
	println("0) Quit");
	println("");
	print("---> ");
	
	cin >> selection;
	
	return selection;
}

void doHire(Database& db)
{
	string firstName;
	string lastName;

	print("First name? ");
	cin >> firstName;

	print("Last name? ");
	cin >> lastName;

	auto& employee{ db.addEmployee(firstName, lastName) };
	println("Hired employee {} {} with employee number {}.",
		firstName, lastName, employee.getEmployeeNumber());
}

void doFire(Database& db)
{
	int employeeNumber;
	print("Employee number? ");
	cin >> employeeNumber;

	try {
		auto& emp{ db.getEmployee(employeeNumber) };
		emp.fire();
		println("Employee {} terminated.", employeeNumber);
	} catch (const std::logic_error& exception) {
		println(cerr, "Unable to terminate employee: {}", exception.what());
	}
}

void doPromote(Database& db)
{
	int employeeNumber;
	print("Employee number? ");
	cin >> employeeNumber;

	int raiseAmount;
	print("How much of a raise? ");
	cin >> raiseAmount;

	try {
		auto& emp{ db.getEmployee(employeeNumber) };
		emp.promote(raiseAmount);
	} catch (const std::logic_error& exception) {
		println(cerr, "Unable to promote employee: {}", exception.what());
	}
}
