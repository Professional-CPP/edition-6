#pragma once

#include "Person.h"
#include <map>
#include <string>
#include <string_view>
#include <vector>

class PhoneBook final
{
public:
	void addPhoneNumber(const Person& person, std::string_view phoneNumber);
	void removePhoneNumber(const Person& person, std::string_view phoneNumber);
	std::vector<std::string> getPhoneNumbers(const Person& person) const;

private:
	std::multimap<Person, std::string> m_phoneBook;
};
