import person;
import std;

using namespace std;

int main()
{
	Person person{ "Kole", "Webb" };
	println("{}, {}", person.getLastName(), person.getFirstName());
}
