export module director;

import employee;

export namespace HR
{
	class Director : public Employee
	{
	public:
		// Explicitly inherit Employee's constructors.
		using Employee::Employee;
	};
}
