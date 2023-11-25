import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	auto myCellp{ make_unique<SpreadsheetCell>() };
	// Equivalent to:
	// unique_ptr<SpreadsheetCell> myCellp{ new SpreadsheetCell{ } };
	
	myCellp->setValue(3.7);
	println("cell 1: {} {}", myCellp->getValue(), myCellp->getString());
}
