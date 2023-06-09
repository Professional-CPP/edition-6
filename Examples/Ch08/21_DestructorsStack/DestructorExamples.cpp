import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 5 };

	if (myCell.getValue() == 5) {
		SpreadsheetCell anotherCell{ 6 };
	} // anotherCell is destroyed as this block ends

	println("myCell: {}", myCell.getValue());

	{
		SpreadsheetCell myCell2{ 4 };
		SpreadsheetCell anotherCell2{ 5 }; // myCell2 constructed before anotherCell2
	} // anotherCell2 destroyed before myCell2
} // myCell is destroyed as this block ends
