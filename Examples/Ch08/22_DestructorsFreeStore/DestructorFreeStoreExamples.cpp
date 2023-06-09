import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell* cellPtr1{ new SpreadsheetCell{ 5 } };
	SpreadsheetCell* cellPtr2{ new SpreadsheetCell{ 6 } };

	println("cellPtr1: {}", cellPtr1->getValue());

	delete cellPtr1; // destroys cellPtr1
	cellPtr1 = nullptr;
} // cellPtr2 is NOT destroyed because delete was not called on it
