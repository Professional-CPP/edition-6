import buddy_list;
import std;

using namespace std;

int main()
{
	BuddyList buddies;

	buddies.addBuddy("Harry Potter", "Ron Weasley");
	buddies.addBuddy("Harry Potter", "Hermione Granger");
	buddies.addBuddy("Harry Potter", "Hagrid");
	buddies.addBuddy("Harry Potter", "Draco Malfoy");
	// That's not right! Remove Draco.
	buddies.removeBuddy("Harry Potter", "Draco Malfoy");

	buddies.addBuddy("Hagrid", "Harry Potter");
	buddies.addBuddy("Hagrid", "Ron Weasley");
	buddies.addBuddy("Hagrid", "Hermione Granger");

	auto harrysFriends{ buddies.getBuddies("Harry Potter") };

	println("Harry's friends: ");
	for (const auto& name : harrysFriends) {
		println("\t{}", name);
	}
}
