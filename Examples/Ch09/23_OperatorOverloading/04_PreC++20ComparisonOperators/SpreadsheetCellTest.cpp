#include "SpreadsheetCell.h"
#include <iostream>

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
		cout << "Caught: " << e.what() << endl;
	}

	aThirdCell -= myCell;
	aThirdCell += 5.4;
	aThirdCell *= myCell;
	aThirdCell /= myCell;

	if (myCell > aThirdCell || myCell < 10) {
		cout << myCell.getValue() << endl;
	}

	if (myCell < 10) {
		cout << "myCell < 10" << endl;
	}

	if (10 < myCell) {
		cout << "10 < myCell" << endl;
	}

	if (anotherCell == myCell) {
		cout << "cells are equal" << endl;
	} else {
		cout << "cells are not equal" << endl;
	}
}
