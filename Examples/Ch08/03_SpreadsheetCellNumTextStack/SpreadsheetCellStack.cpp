import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setString("3.2");

	println("cell 1: {}", myCell.getValue());
	println("cell 2: {}", anotherCell.getValue());

	println("cell 1: {}", myCell.getString());
	println("cell 2: {}", anotherCell.getString());
}
