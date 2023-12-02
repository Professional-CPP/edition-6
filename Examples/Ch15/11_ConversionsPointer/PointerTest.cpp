import pointer;
import spreadsheet_cell;
import std;

using namespace std;

void process(const Pointer<SpreadsheetCell>& p)
{
	if (p != nullptr) { println("not nullptr"); }
	if (p != 0)       { println("not 0"); }
	if (p)            { println("not nullptr"); }
	if (!p)           { println("nullptr"); }
}

int main()
{
	Pointer<SpreadsheetCell> smartCell{ nullptr };
	process(smartCell);
	println("");

	Pointer<SpreadsheetCell> anotherSmartCell{ new SpreadsheetCell{5.0} };
	process(anotherSmartCell);
}
