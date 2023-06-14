export module person;

import std;

export class Person
{
public:
	Person(std::string firstName, std::string lastName);
	Person();
	Person(std::string firstName, std::string lastName, std::string initials);
	~Person();
	Person(const Person& src);
	Person(Person&&) noexcept;
	Person& operator=(const Person& rhs);
	Person& operator=(Person&&) noexcept;

	const std::string& getFirstName() const;
	void setFirstName(std::string firstName);

	const std::string& getLastName() const;
	void setLastName(std::string lastName);

	const std::string& getInitials() const;
	void setInitials(std::string initials);

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};
