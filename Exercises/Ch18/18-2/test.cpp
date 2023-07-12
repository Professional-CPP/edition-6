import person;
import phone_book;
import std;

using namespace std;

int main()
{
	PhoneBook phoneBook;
	phoneBook.addPhoneNumber("John Doe"_p, "123-456-789");
	phoneBook.addPhoneNumber("Jane Doe"_p, "789-456-123");
	phoneBook.addPhoneNumber("John Doe"_p, "999-456-789");
	phoneBook.addPhoneNumber("Marc Gregoire"_p, "258-369-147");
	phoneBook.removePhoneNumber("Marc Gregoire"_p, "258-369-147");
	phoneBook.removePhoneNumber("Marc G"_p, "258-369-147");

	println("John Doe's phone numbers:");
	for (const auto& number : phoneBook.getPhoneNumbers("John Doe"_p)) {
		println("\t{}", number);
	}
}
