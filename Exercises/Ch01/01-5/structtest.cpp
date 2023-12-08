import std;
import employee;

using namespace std;

int main()
{
	vector<HR::Employee> employees;

	employees.push_back(HR::Employee{
		.firstName = "John",
		.lastName = "White",
		.employeeNumber = 42,
		.salary = 80'000,
		.title = HR::Title::SeniorEngineer
		}
	);

	employees.push_back(HR::Employee{
		.firstName = "John",
		.lastName = "Doe",
		.employeeNumber = 133,
		.salary = 64'000,
		.title = HR::Title::Engineer
		}
	);

	employees.push_back(HR::Employee{
		.firstName = "Jane",
		.lastName = "Doe",
		.employeeNumber = 18,
		.salary = 100'000,
		.title = HR::Title::Manager
		}
	);

	for (const auto& employee : employees) {
		// Print the values of an employee
		println("Employee: {} {}", employee.firstName,
			employee.lastName);
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
