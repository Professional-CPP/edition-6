import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 4 };
	myCell = 5;
	myCell = "6"sv; // A string_view literal (see Chapter 2).

	println("Cell: {}", myCell.getValue());
}
