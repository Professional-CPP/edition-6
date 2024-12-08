// Original code snippet.
Employee& Database::getEmployee(int employeeNumber)
{
	for (auto& employee : m_employees) {
		if (employee.getEmployeeNumber() == employeeNumber) {
			return employee;
		}
	}
	throw logic_error { "No employee found." };
}

// First alternative version.
// Curly braces on their own lines.
Employee& Database::getEmployee(int employeeNumber)
{
	for (auto& employee : m_employees)
	{
		if (employee.getEmployeeNumber() == employeeNumber)
		{
			return employee;
		}
	}
	throw logic_error { "No employee found." };
}

// Second alternative version.
// Indent curly braces.
Employee& Database::getEmployee(int employeeNumber)
{
	for (auto& employee : m_employees)
		{
			if (employee.getEmployeeNumber() == employeeNumber)
				{
					return employee;
				}
		}
	throw logic_error { "No employee found." };
}


// Third alternative version.
// Remove curly braces from single-statement code blocks.
Employee& Database::getEmployee(int employeeNumber)
{
	for (auto& employee : m_employees)
		if (employee.getEmployeeNumber() == employeeNumber)
			return employee;
	throw logic_error { "No employee found." };
}
