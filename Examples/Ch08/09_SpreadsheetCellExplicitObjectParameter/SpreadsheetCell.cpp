module spreadsheet_cell;

import std;

using namespace std;

void printCell(const SpreadsheetCell& cell)
{
	println("{}", cell.getString());
}

void SpreadsheetCell::setValue(this SpreadsheetCell& self, double value)
{
	self.m_value = value;
	printCell(self);
}

double SpreadsheetCell::getValue() const
{
	return m_value;
}

void SpreadsheetCell::setString(string_view value)
{
	m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const
{
	return doubleToString(m_value);
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