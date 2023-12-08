import std;
import employee;

using namespace std;

int main()
{
	// Create and populate an employee using designated initializers.
	HR::Employee anEmployee {
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 42,
		.salary = 80'000,
		.title = HR::Title::SeniorEngineer
	};

	// Print the values of an employee
	println("Employee: {}{}", anEmployee.firstInitial, 
		anEmployee.lastInitial);
	println("Number: {}", anEmployee.employeeNumber);
	println("Salary: ${}", anEmployee.salary);

	switch (anEmployee.title)
	{
		using enum HR::Title;

		case Engineer:
			println("Engineer");
			break;
		case SeniorEngineer:
			println("Senior Engineer");
			break;
		case Manager:
			println("Manager");
			break;
	}
}
