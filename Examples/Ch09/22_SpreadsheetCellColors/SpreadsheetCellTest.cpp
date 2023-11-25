import spreadsheet_cell;

using namespace std;

int main()
{
	SpreadsheetCell myCell { 5 };
	myCell.setColor(SpreadsheetCell::Color::Blue);
	auto color{ myCell.getColor() };
}
