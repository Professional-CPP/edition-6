module spreadsheet_cell;

import std;

using namespace std;

void printCell(const SpreadsheetCell& cell)
{
	println("{}", cell.getString());
}

void SpreadsheetCell::setValue(double value)
{
	this->value = value;
	printCell(*this);
}

double SpreadsheetCell::getValue() const
{
	return value;
}

void SpreadsheetCell::setString(string_view value)
{
	this->value = stringToDouble(value);
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
