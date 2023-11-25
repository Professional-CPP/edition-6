import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ "6.2" };
	println("cell 1: {}", myCell.getValue());
}
