import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell* myCellp{ new SpreadsheetCell{ } };

	(*myCellp).setValue(3.7);
	println("cell 1: {} {}", (*myCellp).getValue(), (*myCellp).getString());
	delete myCellp;
	myCellp = nullptr;
}
