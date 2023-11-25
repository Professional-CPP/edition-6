import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell { 4 }, anotherCell { 5 };
	SpreadsheetCell aThirdCell{ myCell + anotherCell };
	//SpreadsheetCell aThirdCell{ myCell.operator+(anotherCell) };
	auto aFourthCell{ aThirdCell + anotherCell };
	println("{}", aThirdCell.getValue());

	string str{ "hello" };
	aThirdCell = myCell + string_view{ str };
	
	aThirdCell = myCell + 5.6;
	aThirdCell = myCell + 4;

	// The following two lines don't compile
	// aThirdCell = 5.6 + myCell; // FAILS TO COMPILE!
	// aThirdCell = 4 + myCell;   // FAILS TO COMPILE!
}
