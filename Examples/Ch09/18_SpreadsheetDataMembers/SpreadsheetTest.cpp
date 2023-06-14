import spreadsheet;
import std;

using namespace std;

int main()
{
	SpreadsheetApplication app;
	Spreadsheet s1 { 2, 3, app };
	Spreadsheet s2 { 3, 4, app };

	println("Maximum height is: {}", Spreadsheet::MaxHeight);
}
