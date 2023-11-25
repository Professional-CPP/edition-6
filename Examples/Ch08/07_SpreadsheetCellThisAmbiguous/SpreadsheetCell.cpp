module spreadsheet_cell;

import std;

using namespace std;

void SpreadsheetCell::setValue(double value)
{
	value = value; // Confusing!
}

double SpreadsheetCell::getValue() const
{
	return value;
}

void SpreadsheetCell::setString(string_view value)
{
	value = stringToDouble(value);
}

string SpreadsheetCell::getString() const
{
	return doubleToString(value);
}

string SpreadsheetCell::doubleToString(double value) const
{
	return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value) const
{
	double number{ 0 };
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}
