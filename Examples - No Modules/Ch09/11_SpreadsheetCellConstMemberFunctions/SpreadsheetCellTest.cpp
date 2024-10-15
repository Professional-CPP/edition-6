#include "SpreadsheetCell.h"
#include <print>

using namespace std;

int main()
{
	SpreadsheetCell myCell { 5 };
	println("{}", myCell.getValue());       // OK
	myCell.setString("6");                  // OK

	const SpreadsheetCell& myCellConstRef{ myCell };
	println("{}", myCellConstRef.getValue()); // OK
	//myCellConstRef.setString("6"); // Compilation Error!
}
