export module employee;

namespace HR {

	//// Use a type-safe enum class enumeration.
	export enum class Title {
		Engineer,
		SeniorEngineer,
		Manager
	};

	export struct Employee {
		char firstInitial;
		char lastInitial;
		int employeeNumber;
		int salary;
		Title title;
	};

}
