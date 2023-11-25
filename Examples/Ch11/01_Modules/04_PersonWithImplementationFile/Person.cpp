module person;

using namespace std;

Person::Person(string firstName, string lastName)
	: m_firstName{ move(firstName) }, m_lastName{ move(lastName) }
{
}

const string& Person::getFirstName() const
{
	return m_firstName;
}

const string& Person::getLastName() const
{
	return m_lastName;
}
