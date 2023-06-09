import spreadsheet_cell;

int main()
{
	// Comment out these next two lines to test the third line
	SpreadsheetCell cells[3]; // FAILS compilation without a default constructor
	SpreadsheetCell* myCellp{ new SpreadsheetCell[10] }; // also FAILS

	// This line compiles without a default constructor
	SpreadsheetCell cells[3]{ SpreadsheetCell{ 0 }, SpreadsheetCell{ 23 },
					SpreadsheetCell{ 41 } };
}
