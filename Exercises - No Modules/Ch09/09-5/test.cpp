#include "Person.h"
#include <print>

using namespace std;

int main()
{
	Person person { "John", "Doe" };
	println("Initials = {}", person.getInitials());

	println("Initials = {}", Person{ "Marc", "Gregoire" }.getInitials());
}
