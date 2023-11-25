import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 5 }, anotherCell{ 4 };
	println("cell 1: {}", myCell.getValue());
	println("cell 2: {}", anotherCell.getValue());

	auto smartCellp{ make_unique<SpreadsheetCell>(4) };
	// ... do something with the cell, no need to delete the smart pointer

	// Or with raw pointers, without smart pointers (not recommended)
	SpreadsheetCell* myCellp{ new SpreadsheetCell{ 5 } };
	// Or
	// SpreadsheetCell* myCellp{ new SpreadsheetCell(5) };
	SpreadsheetCell* anotherCellp{ nullptr };
	anotherCellp = new SpreadsheetCell{ 4 };
	// ... do something with the cells
	delete myCellp; 		myCellp = nullptr;
	delete anotherCellp; 	anotherCellp = nullptr;

	SpreadsheetCell aThirdCell{ "test" };  // uses string-arg ctor
	SpreadsheetCell aFourthCell{ 4.4 };    // uses double-arg ctor
	auto aFifthCellp{ make_unique<SpreadsheetCell>("5.5") }; // string-arg ctor
	println("aThirdCell: {}", aThirdCell.getValue());
	println("aFourthCell: {}", aFourthCell.getValue());
	println("aFifthCellp: {}", aFifthCellp->getValue());
}
