import pointer;
import spreadsheet_cell;
import std;

using namespace std;

void testConstPointerInt(const Pointer<int>& p)
{
	println("{} ", *p);
	// *p = 7;
}

void testConstPointerCell(const Pointer<SpreadsheetCell>& p)
{
	println("{} ", p->getValue());
	// p->set(5);
}

int main()
{
	Pointer<int> smartInt{ new int };
	*smartInt = 5; // Dereference the smart pointer.
	println("{} ", *smartInt);
	testConstPointerInt(smartInt);

	Pointer<SpreadsheetCell> smartCell{ new SpreadsheetCell };
	smartCell->set(5); // Dereference and member select the set() member function.
	println("{} ", smartCell->getValue());
	testConstPointerCell(smartCell);
}
