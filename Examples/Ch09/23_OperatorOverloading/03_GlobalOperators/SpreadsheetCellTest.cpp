import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell myCell { 4 }, anotherCell { 5 };
	SpreadsheetCell aThirdCell{ myCell + anotherCell };

	string str{ "hello" };
	aThirdCell = myCell + string_view{ str };

	aThirdCell = myCell + 5.6;
	aThirdCell = myCell + 4;

	aThirdCell = 5.6 + myCell; // works fine
	aThirdCell = 4 + myCell;   // works fine
	aThirdCell = 4.5 + 5.5;

	aThirdCell = myCell - anotherCell;
	aThirdCell = myCell * anotherCell;
	aThirdCell = myCell / anotherCell;

	try {
		aThirdCell = myCell / 0;
	} catch (const invalid_argument& e) {
		println("Caught: {}", e.what());
	}

	aThirdCell -= myCell;
	aThirdCell += 5.4;
	aThirdCell *= myCell;
	aThirdCell /= myCell;
}
