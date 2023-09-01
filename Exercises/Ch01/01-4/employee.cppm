export module employee;

namespace HR {

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
