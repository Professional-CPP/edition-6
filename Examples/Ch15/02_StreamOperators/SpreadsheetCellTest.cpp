import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	int number{ 10 };
	cout << "The number is " << number << endl;
	
	cout << "Enter a number and a string: ";
	string str;
	cin >> number >> str;
	cout << "You entered: " << number << " and " << str << endl;

	SpreadsheetCell myCell, anotherCell, aThirdCell;

	cout << "Input 3 spreadsheetcells:" << endl;
	cin >> myCell >> anotherCell >> aThirdCell;
	cout << myCell << " " << anotherCell << " " << aThirdCell << endl;

	cout << "Input 3 spreadsheetcells:" << endl;
	operator>>(operator>>(operator>>(cin, myCell), anotherCell), aThirdCell);
}
