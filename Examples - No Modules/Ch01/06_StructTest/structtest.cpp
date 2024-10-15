#include <print>
#include "employee.h"

using namespace std;

int main()
{
	// create and populate an employee
	Employee anEmployee;
	anEmployee.firstInitial = 'J';
	anEmployee.lastInitial = 'D';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;

	// output the values of an employee
	println("Employee: {}{}", anEmployee.firstInitial,
		anEmployee.lastInitial);
	println("Number: {}", anEmployee.employeeNumber);
	println("Salary: ${}", anEmployee.salary);
}
