import access_list;
import std;

using namespace std;

int main()
{
	AccessList fileX{ "mgregoire", "baduser" };
	fileX.addUser("pvw");
	fileX.removeUser("baduser");

	if (fileX.isAllowed("mgregoire")) {
		println("mgregoire has permissions");
	}

	if (fileX.isAllowed("baduser")) {
		println("baduser has permissions");
	}

	//  C++23 supports formatting/printing of ranges.
	println("Users with access: {:n:}", fileX.getAllUsers());

	// Iterating over the elements of a set.
	print("Users with access: ");
	for (const auto& user : fileX.getAllUsers()) {
		print("{} ", user);
	}
	println("");

	// Iterating over the elements of a vector.
	print("Users with access: ");
	for (const auto& user : fileX.getAllUsersAsVector()) {
		print("{} ", user);
	}
	println("");
}
