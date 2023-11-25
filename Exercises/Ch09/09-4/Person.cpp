module person;

import std;

using namespace std;

// Person::Impl class definition
class Person::Impl
{
public:
	explicit Impl(string firstName, string lastName);
	Impl() = default;
	explicit Impl(string firstName, string lastName, string initials);

	const string& getFirstName() const;
	void setFirstName(string firstName);

	const string& getLastName() const;
	void setLastName(string lastName);

	const string& getInitials() const;
	void setInitials(string initials);

private:
	string m_firstName;
	string m_lastName;
	string m_initials;
};


// Person::Impl class member function definitions.

// Two-parameter constructor automatically creates initials.
// 
// Warning: delegating to the 3-parameter constructor as follows doesn't work:
//		Person::Impl::Impl(string firstName, string lastName)
//			: Impl{ move(firstName), move(lastName),
//			format("{}{}", firstName[0], lastName[0]) }
// because then firstName and lastName could already have been moved into
// temporary std::strings before firstName[O] and lastName[O] are used in
// the call to std::format().
Person::Impl::Impl(string firstName, string lastName)
	: m_firstName{ move(firstName) }
	, m_lastName{ move(lastName) }
{
	m_initials = format("{}{}", m_firstName[0], m_lastName[0]);
}

Person::Impl::Impl(string firstName, string lastName, string initials)
	: m_firstName{ move(firstName) }
	, m_lastName{ move(lastName) }
	, m_initials{ move(initials) }
{
}

const string& Person::Impl::getFirstName() const { return m_firstName; }
void Person::Impl::setFirstName(string firstName) { m_firstName = move(firstName); }

const string& Person::Impl::getLastName() const { return m_lastName; }
void Person::Impl::setLastName(string lastName) { m_lastName = move(lastName); }

const string& Person::Impl::getInitials() const { return m_initials; }
void Person::Impl::setInitials(string initials) { m_initials = move(initials); }



// Person class member function definitions.

Person::Person(string firstName, string lastName)
	: m_impl{ make_unique<Impl>(move(firstName), move(lastName)) }
{
}

Person::Person(string firstName, string lastName, string initials)
	: m_impl{ make_unique<Impl>(move(firstName), move(lastName), move(initials)) }
{
}

Person::Person()
	: m_impl{ make_unique<Impl>() }
{
}

Person::~Person() = default;
Person::Person(Person&&) noexcept = default;
Person& Person::operator=(Person&&) noexcept = default;

Person::Person(const Person& src)
	: m_impl{ make_unique<Impl>(*src.m_impl) }
{
}

Person& Person::operator=(const Person& rhs)
{
	*m_impl = *rhs.m_impl;
	return *this;
}

const string& Person::getFirstName() const { return m_impl->getFirstName(); }
void Person::setFirstName(string firstName) { m_impl->setFirstName(move(firstName)); }

const string& Person::getLastName() const { return m_impl->getLastName(); }
void Person::setLastName(string lastName) { m_impl->setLastName(move(lastName)); }

const string& Person::getInitials() const { return m_impl->getInitials(); }
void Person::setInitials(string initials) { m_impl->setInitials(move(initials)); }
