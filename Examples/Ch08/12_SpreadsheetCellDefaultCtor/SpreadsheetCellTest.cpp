import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell;
	// Or
	// SpreadsheetCell myCell { }; // Calls the default constructor.
	myCell.setValue(6);
	println("cell 1: {}", myCell.getValue());

	auto smartCellp{ make_unique<SpreadsheetCell>() };

	// Or with a raw pointer (not recommended)
	SpreadsheetCell* myCellp{ new SpreadsheetCell{ } };
	// Or
	// SpreadsheetCell* myCellp{ new SpreadsheetCell };
	// Or
	// SpreadsheetCell* myCellp{ new SpreadsheetCell() };
	// ... use myCellp
	delete myCellp;    myCellp = nullptr;
}
