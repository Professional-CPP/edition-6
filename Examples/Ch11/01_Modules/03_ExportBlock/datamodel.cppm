export module datamodel;

import std;

export
{
	namespace DataModel
	{
		class Person { /* ... */ };

		class Address { /* ... */ };

		using Persons = std::vector<Person>;
	}
}
