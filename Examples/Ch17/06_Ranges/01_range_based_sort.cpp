import std;

using namespace std;

class Person
{
public:
	explicit Person(string first, string last)
		: m_firstName{ move(first) }, m_lastName{ move(last) } { }

	const string& getFirstName() const { return m_firstName; }
	const string& getLastName() const { return m_lastName; }

private:
	string m_firstName;
	string m_lastName;
};

int main()
{
	vector data{ 33, 11, 22 };
	sort(begin(data), end(data));
	ranges::sort(data);



	vector persons{ Person{"John", "White"}, Person{"Chris", "Blue"} };

	//sort(begin(persons), end(persons)); // Error: does not compile.
	//ranges::sort(persons); // Error: does not compile.

	//ranges::sort(persons, {},
	//	[](const Person& person) { return person.getFirstName(); });
	// Or:
	ranges::sort(persons, {}, &Person::getFirstName);
	
	for (const auto& person : persons) { println("{}", person.getFirstName()); }
}
