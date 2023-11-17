export module person;

import std;

export class Person
{
public:
	explicit Person(const std::string& firstName, const std::string& lastName)
		: m_firstName{ firstName }, m_lastName{ lastName }
	{}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(const std::string& firstName) { m_firstName = firstName; }

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(const std::string& lastName) { m_lastName = lastName; }

private:
	std::string m_firstName;
	std::string m_lastName;
};

//// NOTE: the above solution uses "const std::string&" as type for the
////       parameters. This is not always optimal. You could use
////       std::string_view as parameter type, but this is not always
////       optimal either.
////       The optimal solution is to pass std::string by value and move
////       from the parameter. This is explained in the section
////       "Optimal Way to Pass Arguments to Functions" in Chapter 9.
////       As a sneak preview, below is a solution using that technique.

//export class Person
//{
//public:
//	Person(std::string firstName, std::string lastName)
//		: m_firstName{ std::move(firstName) }
//		, m_lastName{ std::move(lastName) }
//	{}
//
//	const std::string& getFirstName() const { return m_firstName; }
//	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }
//
//	const std::string& getLastName() const { return m_lastName; }
//	void setLastName(std::string lastName) { m_lastName = std::move(lastName); }
//
//private:
//	std::string m_firstName;
//	std::string m_lastName;
//};
