import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell cell{ 1.23 };
	
	double d1{ cell };
	println("{}", d1);

	string str1 = cell;
	println("{}", str1);

	string str2{ static_cast<string>(cell) };
	println("{}", str2);
}
