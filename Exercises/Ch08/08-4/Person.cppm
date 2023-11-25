export module person;

import std;

export class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	explicit Person(const std::string& firstName, const std::string& lastName)
		: Person{ firstName, lastName, std::format("{}{}", firstName[0], lastName[0]) }
	{
	}

	Person() = default;

	explicit Person(const std::string& firstName, const std::string& lastName, const std::string& initials)
		: m_firstName{ firstName }, m_lastName{ lastName }, m_initials{ initials }
	{}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(const std::string& firstName) { m_firstName = firstName; }

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(const std::string& lastName) { m_lastName = lastName; }

	const std::string& getInitials() const { return m_initials; }
	void setInitials(const std::string& initials) { m_initials = initials; }

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};

//// NOTE: the above solution uses "const std::string&" as type for the
////       parameters. This is not always optimal. You could use
////       std::string_view as parameter type, but this is not always
////       optimal either.
////       The optimal solution is to pass std::string by value and move
////       from the parameter. This is explained in the section
////       "Optimal Way to Pass Arguments to Functions" in Chapter 9.
////       See the solution for Exercise 8-1 for an example of using
////       that technique.
