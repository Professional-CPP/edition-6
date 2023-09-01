export module employee;

import std;

namespace HR {

	export enum class Title {
		Engineer,
		SeniorEngineer,
		Manager
	};

	export struct Employee {
		std::string firstName;
		std::string lastName;
		int employeeNumber;
		int salary;
		Title title;
	};

}
