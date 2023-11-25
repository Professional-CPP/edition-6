export module manager;

import employee;

export namespace HR
{
	class Manager : public Employee
	{
	public:
		// Explicitly inherit Employee's constructors.
		using Employee::Employee;
	};
}
