import std;

using namespace std;

struct Employee {
	char firstInitial;
	char lastInitial;
	int  employeeNumber;
	int  salary{ 75'000 };
};

int main()
{
	{
		int* myIntegerPointer{ nullptr };
		if (!myIntegerPointer) { /* myIntegerPointer is a null pointer */ }
		myIntegerPointer = new int;
		*myIntegerPointer = 8;
		delete myIntegerPointer;
		myIntegerPointer = nullptr;
	}


	{
		int i{ 8 };
		int* myIntegerPointer{ &i };  // Points to the variable with the value 8
	}


	{
		Employee* anEmployee{ new Employee{ 'J', 'D', 42, 80'000 } };
		
		println("{}", (*anEmployee).salary);
		println("{}", anEmployee->salary);
		
		bool isValidSalary1{ anEmployee && anEmployee->salary > 0 };
		bool isValidSalary2{ anEmployee != nullptr && anEmployee->salary > 0 };

		delete anEmployee; anEmployee = nullptr;
	}
}
