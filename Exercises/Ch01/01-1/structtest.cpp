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
		.salary = 80'000
	};

	// Print the values of an employee
	println("Employee: {}{}", anEmployee.firstInitial, 
		anEmployee.lastInitial);
	println("Number: {}", anEmployee.employeeNumber);
	println("Salary: ${}", anEmployee.salary);
}
