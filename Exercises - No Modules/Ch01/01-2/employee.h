#pragma once

namespace HR {

	//// Use a strongly typed enum class enumeration.
	enum class Title {
		Engineer,
		SeniorEngineer,
		Manager
	};

	struct Employee {
		char firstInitial;
		char lastInitial;
		int employeeNumber;
		int salary;
		Title title;
	};

}
