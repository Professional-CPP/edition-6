import person;
import std;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };
	println("{} {}", person.getFirstName(), person.getLastName());

	Person persons[3];

	// Test copy constructor.
	Person copy{ person };

	// Test assignment operator.
	Person otherPerson{ "Jane", "Doe" };
	copy = otherPerson;
}
