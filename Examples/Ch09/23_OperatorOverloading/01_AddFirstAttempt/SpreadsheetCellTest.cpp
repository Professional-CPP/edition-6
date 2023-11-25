import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell { 4 } , anotherCell {5 };
	SpreadsheetCell aThirdCell{ myCell.add(anotherCell) };
	auto aFourthCell{ aThirdCell.add(anotherCell) };
	println("{}", aThirdCell.getValue());
}
