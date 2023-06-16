export module person;

import std;

export class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	Person(std::string firstName, std::string lastName)
		: Person{ std::move(firstName), std::move(lastName),
		std::format("{}{}", firstName[0], lastName[0]) }
	{
	}

	Person() = default;

	Person(std::string firstName, std::string lastName, std::string initials)
		: m_firstName{ std::move(firstName) }
		, m_lastName{ std::move(lastName) }
		, m_initials{ std::move(initials) }
	{
	}

	// Using C++23 explicit object parameters.
	const std::string& getFirstName(this const Person& self) { return self.m_firstName; }
	std::string&& getFirstName(this Person&& self) { return std::move(self.m_firstName); }
	// Using standard ref-qualifiers.
	//const std::string& getFirstName() const & { return m_firstName; }
	//std::string&& getFirstName() && { return std::move(m_firstName); }
	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }

	// Using C++23 explicit object parameters.
	const std::string& getLastName(this const Person& self) { return self.m_lastName; }
	std::string&& getLastName(this Person&& self) { return std::move(self.m_lastName); }
	// Using standard ref-qualifiers.
	//const std::string& getLastName() const & { return m_lastName; }
	//std::string&& getLastName() && { return std::move(m_lastName); }
	void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

	// Using C++23 explicit object parameters.
	const std::string& getInitials(this const Person& self) { return self.m_initials; }
	std::string&& getInitials(this Person&& self) { return std::move(self.m_initials); }
	// Using standard ref-qualifiers.
	//const std::string& getInitials() const & { return m_initials; }
	//std::string&& getInitials() && { return std::move(m_initials); }
	void setInitials(std::string initials) { m_initials = std::move(initials); }

	// Only this single line of code is needed to add support
	// for all six comparison operators.
	[[nodiscard]] auto operator<=>(const Person&) const = default;

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};
