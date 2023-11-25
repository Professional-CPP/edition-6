import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell1{ 4 };
	SpreadsheetCell myCell2{ myCell1 };
	// myCell2 has the same values as myCell1

	println("Cell 1: {}", myCell1.getValue());
	println("Cell 2: {}", myCell2.getValue());
}
