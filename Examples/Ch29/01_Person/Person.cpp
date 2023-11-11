import std;

using namespace std;

class Person
{
public:
	Person();
	explicit Person(string firstName, string lastName, int age);
	Person(const Person& rhs);
	virtual ~Person();

	const string& getFirstName() const { return m_firstName; }
	const string& getLastName() const { return m_lastName; }
	int getAge() const { return m_age; }

private:
	string m_firstName, m_lastName;
	int m_age{ 0 };
};

Person::Person()
{
	println("Default Ctor");
}

Person::Person(string firstName, string lastName, int age)
	: m_firstName{ move(firstName) }, m_lastName{ move(lastName) }, m_age{ age }
{
	println("Ctor");
}

Person::~Person()
{
	println("Dtor");
}

Person::Person(const Person& rhs)
	: m_firstName{ rhs.m_firstName }, m_lastName{ rhs.m_lastName }, m_age{ rhs.m_age }
{
	println("Copy ctor");
}

ostream& operator<<(ostream& ostr, const Person& p)
{
	ostr << p.getFirstName() << " " << p.getLastName() <<
		" " << p.getAge() << endl;

	return ostr;
}


/*
void processPerson(Person p)
{
// process the person
}
*/


void processPerson(const Person& /*p*/)
{
	// process the person
}

int main()
{
	Person me{ "Marc", "Gregoire", 42 };
	processPerson(me);
}
