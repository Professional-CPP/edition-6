module spreadsheet_cell;

import std;

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: m_value { initialValue }
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
	: m_value { stringToDouble(initialValue) }
{
}

void SpreadsheetCell::set(double value)
{
	m_value = value;
}

double SpreadsheetCell::getValue() const
{
	return m_value;
}

void SpreadsheetCell::set(string_view value)
{
	m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const
{
	return doubleToString(m_value);
}

string SpreadsheetCell::doubleToString(double value)
{
	return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value)
{
	double number{ 0 };
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const
{
	return SpreadsheetCell { getValue() + cell.getValue() };
}

/*
SpreadsheetCell SpreadsheetCell::operator+(double rhs) const
{
	return SpreadsheetCell { getValue() + rhs };
}
*/
