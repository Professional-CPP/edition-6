export module person;

import std;

export class Person
{
public:
	explicit Person(std::string firstName, std::string lastName) //// Pass by value and move.
		: m_firstName{ std::move(firstName) }, m_lastName{ std::move(lastName) }
	{
	}

	Person() = default;

	// Copy constructor.
	Person(const Person& src)
		: m_firstName{ src.m_firstName }, m_lastName{ src.m_lastName }
	{
		std::println("Person copy constructor called.");
	}

	// Assignment operator.
	//// Modified to use copy-and-swap to avoid code duplication.
	Person& operator=(const Person& rhs)
	{
		std::println("Person assignment operator called.");

		auto temp{ rhs };
		swap(temp);
		return *this;
	}

	// Destructor.
	~Person()
	{
		std::println("Person destructor called.");
	}

	// Move constructor.
	Person(Person&& src) noexcept
	{
		std::println("Person move constructor called.");
		swap(src);
	}

	// Move assignment operator.
	Person& operator=(Person&& rhs) noexcept
	{
		std::println("Person move assignment operator called.");
		auto moved{ std::move(rhs) };
		swap(moved);
		return *this;
	}

	// swap member function.
	//// Added to avoid code duplication
	void swap(Person& other) noexcept
	{
		std::swap(m_firstName, other.m_firstName);
		std::swap(m_lastName, other.m_lastName);
	}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); } //// Pass by value and move.

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(std::string lastName) { m_lastName = std::move(lastName); } //// Pass by value and move.

private:
	std::string m_firstName;
	std::string m_lastName;
};