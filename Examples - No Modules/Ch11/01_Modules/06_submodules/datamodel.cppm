export module datamodel;          // datamodel module

export import datamodel.person;   // Import and export person submodule
export import datamodel.address;  // Import and export address submodule

import std;

export namespace DataModel
{
	using Persons = std::vector<Person>;
}
