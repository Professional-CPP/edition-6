//void Database::displayCurrent() const         // The displayCurrent() member function.
//{
//	for (const auto& employee : m_employees) {  // For each employee...
//		if (employee.isHired()) {               // If the employee is hired
//			employee.display();                 // Then display that employee
//		}
//	}
//}



//// The above comments are useless.
//// They simply explain in English what each line of code is doing.
//// Below is a better use of comments for this code snippet.

void Database::displayCurrent() const
{
	// Display all hired employees.
	for (const auto& employee : m_employees) {
		if (employee.isHired()) {
			employee.display();
		}
	}
}



//// Even that one line of comment is not that useful.
//// So, this displayCurrent() member function does not really
//// require any comments, as the code is self-documenting.

void Database::displayCurrent() const
{
	for (const auto& employee : m_employees) {
		if (employee.isHired()) {
			employee.display();
		}
	}
}
