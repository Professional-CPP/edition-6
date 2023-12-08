import std;
import employee;

using namespace std;

int main()
{
	// Create and populate 3 employees using designated initializers.
	HR::Employee employee1{
		.firstInitial = 'J',
		.lastInitial = 'W',
		.employeeNumber = 42,
		.salary = 80'000,
		.title = HR::Title::SeniorEngineer
	};

	HR::Employee employee2{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 133,
		.salary = 64'000,
		.title = HR::Title::Engineer
	};

	HR::Employee employee3{
		.firstInitial = 'B',
		.lastInitial = 'P',
		.employeeNumber = 18,
		.salary = 100'000,
		.title = HR::Title::Manager
	};

	array<HR::Employee, 3> employees{
		employee1, employee2, employee3
	};

	for (const auto& employee : employees) {
		// Print the values of an employee
		println("Employee: {}{}", employee.firstInitial,
			employee.lastInitial);
		println("Number: {}", employee.employeeNumber);
		println("Salary: ${}", employee.salary);

		switch (employee.title)
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
		println("");
	}
}
