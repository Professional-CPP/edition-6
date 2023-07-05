import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	int i, j{ 4 };
	i = -j; // Unary minus
	i = +i; // Unary plus
	j = +(-i); // Apply unary plus to the result of applying unary minus to i.
	j = -(-i); // Apply unary minus to the result of applying unary minus to i.

	i = i + 1;
	i += 1;
	++i;
	i++;

	SpreadsheetCell c1{ 4 };
	SpreadsheetCell c2{ 4 };
	SpreadsheetCell c3{ -c1 };
	c1++;
	++c2;
}
