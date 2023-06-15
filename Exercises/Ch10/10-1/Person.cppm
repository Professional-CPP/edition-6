export module person;

import std;

export namespace HR
{
	class Person
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

		virtual ~Person() = default; // A virtual destructor!

		virtual const std::string& getFirstName() const { return m_firstName; }
		virtual void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }

		virtual const std::string& getLastName() const { return m_lastName; }
		virtual void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

		virtual const std::string& getInitials() const { return m_initials; }
		virtual void setInitials(std::string initials) { m_initials = std::move(initials); }

	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_initials;
	};
}
