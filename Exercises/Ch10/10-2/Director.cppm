export module director;

import employee;
import std;

export namespace HR
{
	class Director : public Employee
	{
	public:
		// Explicitly inherit Employee's constructors.
		using Employee::Employee;

		std::string toString() const override
		{
			return std::format("Director is {}", Employee::toString());
		}
	};
}
