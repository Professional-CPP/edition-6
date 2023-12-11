module phone_book;

import std;

using namespace std;

void PhoneBook::addPhoneNumber(const Person& person, string_view phoneNumber)
{
	m_phoneBook.emplace(person, phoneNumber);
}

void PhoneBook::removePhoneNumber(const Person& person, string_view phoneNumber)
{
	auto [begin, end]{ m_phoneBook.equal_range(person) };
	for (auto iter{ begin }; iter != end; ++iter) {
		if (iter->second == phoneNumber) {
			m_phoneBook.erase(iter);
			break;
		}
	}
}

vector<string> PhoneBook::getPhoneNumbers(const Person& person) const
{
	auto [begin, end]{ m_phoneBook.equal_range(person) };
	
	// Using C++23 ranges functionality.
	return ranges::subrange{ begin, end } | views::values | ranges::to<vector>();
	
	// Before C++23.
	//vector<string> phoneNumbers;
	//for (auto iter{ begin }; iter != end; ++iter) {
	//	phoneNumbers.push_back(iter->second);
	//}
	//return phoneNumbers;
}
