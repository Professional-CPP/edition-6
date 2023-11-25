export module manager;

import employee;
import std;

export namespace HR
{
	class Manager : public Employee
	{
	public:
		// Explicitly inherit Employee's constructors.
		using Employee::Employee;

		// Constructor to convert from Employee to Manager.
		explicit Manager(const Employee& employee)
			: Employee{ employee }
		{
		}

		std::string toString() const override
		{
			return std::format("Manager is {}", Employee::toString());
		}
	};
}
