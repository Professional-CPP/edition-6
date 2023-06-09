import person;
import std;

using namespace std;

int main()
{
	// On the stack:
	Person person1{ "John", "Doe" };
	println("{} {}", person1.getFirstName(), person1.getLastName());

	// On the free store:
	auto person2{ make_unique<Person>("Marc", "Gregoire") };
	println("{} {}", person2->getFirstName(), person2->getLastName());
}
