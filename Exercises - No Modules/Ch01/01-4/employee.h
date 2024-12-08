#pragma once

namespace HR {

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
