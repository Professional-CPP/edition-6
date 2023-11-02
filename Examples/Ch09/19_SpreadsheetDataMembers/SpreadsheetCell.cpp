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
