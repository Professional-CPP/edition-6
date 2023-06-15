import std;
import double_spreadsheet_cell;
import string_spreadsheet_cell;

using namespace std;

int main()
{
	vector<unique_ptr<SpreadsheetCell>> cellArray;

	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<DoubleSpreadsheetCell>());

	cellArray[0]->set("hello");
	cellArray[1]->set("10");
	cellArray[2]->set("18");

	println("Vector: [{},{},{}]", cellArray[0]->getString(),
		cellArray[1]->getString(),
		cellArray[2]->getString());

	{
		DoubleSpreadsheetCell doubleCell;
		doubleCell.set(8.4);
		DoubleSpreadsheetCell result{ doubleCell + doubleCell };
		println("{}", result.getString());  // Prints 16.800000
	}

	{
		DoubleSpreadsheetCell doubleCell;
		doubleCell.set(8.4);
		StringSpreadsheetCell stringCell;
		stringCell.set("Hello ");
		StringSpreadsheetCell result{ stringCell + doubleCell };
		println("{}", result.getString());  // Prints Hello 8.400000
	}
}
