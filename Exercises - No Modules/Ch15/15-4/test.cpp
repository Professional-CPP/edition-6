#include "Person.h"
#include <print>

using namespace std;

int main()
{
	auto peter{ "Peter Van Weert"_p };

	println("First name: '{}'", peter.getFirstName());
	println("Last name: '{}'", peter.getLastName());
	println("Initials: '{}'", peter.getInitials());
}
