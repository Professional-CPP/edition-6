import person;
import std;

using namespace std;

int main()
{
	Person person { "John", "Doe" };
	println("The initials of {} {} are {}.",
		person.getFirstName(), person.getLastName(), person.getInitials());

	Person person2 { "Marc", "Gregoire", "Mg" };
	println("The initials of {} {} are {}.",
		person2.getFirstName(), person2.getLastName(), person2.getInitials());

	Person persons[3];

	// Test copy constructor.
	Person copy{ person };

	// Test assignment operator.
	Person otherPerson { "Jane", "Doe" };
	copy = otherPerson;

	// Test move construction.
	Person moved{ move(copy) };

	// Test move assignment operator.
	Person moved2;
	moved2 = move(otherPerson);
}
