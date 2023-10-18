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

	aThirdCell = 4 + myCell;   // works fine
	aThirdCell = 5.6 + myCell; // works fine
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

	if (myCell > aThirdCell || myCell < 10) {
		println("{}", myCell.getValue());
	}

	if (myCell == 10) { println("myCell == 10"); }
	if (10 == myCell) { println("10 == myCell"); }

	if (myCell < aThirdCell) { println("myCell < aThirdCell"); }
	if (aThirdCell < myCell) { println("aThirdCell < myCell"); }

	if (myCell <= aThirdCell) { println("myCell <= aThirdCell"); }
	if (aThirdCell <= myCell) { println("aThirdCell <= myCell"); }

	if (myCell > aThirdCell) { println("myCell> aThirdCell"); }
	if (aThirdCell > myCell) { println("aThirdCell> myCell"); }

	if (myCell >= aThirdCell) { println("myCell>= aThirdCell"); }
	if (aThirdCell >= myCell) { println("aThirdCell>= myCell"); }

	if (myCell == aThirdCell) { println("myCell == aThirdCell"); }
	if (aThirdCell == myCell) { println("aThirdCell == myCell"); }

	if (myCell != aThirdCell) { println("myCell != aThirdCell"); }
	if (aThirdCell != myCell) { println("aThirdCell != myCell"); }

	if (myCell < 10) { println("myCell < 10"); }
	if (10 < myCell) { println("10 < myCell"); }
	if (10 != myCell) { println("10 != myCell"); }

	if (anotherCell == myCell) {
		println("cells are equal");
	} else {
		println("cells are not equal");
	}
}
