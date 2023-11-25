import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 5 };
	println("{}", myCell.getValue());
}
