export module database;

import std;
import employee;

namespace Records {
	const int FirstEmployeeNumber{ 1'000 };

	export class Database
	{
	public:
		Employee& addEmployee(const std::string& firstName,
							  const std::string& lastName);
		Employee& getEmployee(int employeeNumber);
		Employee& getEmployee(const std::string& firstName,
							  const std::string& lastName);

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Employee> m_employees;
		int m_nextEmployeeNumber{ FirstEmployeeNumber };
	};
}
