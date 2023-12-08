import employee;
import std;

using namespace std;
using namespace Records;

int main()
{
	{
		// Old style:
		//int (Employee::*functionPtr) () const { &Employee::getSalary };

		// Using a type alias:
		//using PtrToGet = int (Employee::*) () const;
		//PtrToGet functionPtr{ &Employee::getSalary };

		// Using auto:
		auto functionPtr{ &Employee::getSalary };

		Employee employee{ "John", "Doe" };
		println("{}", (employee.*functionPtr)());
	}

	{
		int (Employee::*functionPtr) () const { &Employee::getSalary };
		Employee johnD{ "John", "Doe" };
		Employee* employee{ &johnD };
		println("{}", (employee->*functionPtr)());
	}
}
