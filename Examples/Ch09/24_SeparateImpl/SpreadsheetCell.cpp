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

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result += rhs;       // Forward to +=()
	return result;
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result -= rhs;       // Forward to -=()
	return result;
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result *= rhs;       // Forward to *=()
	return result;
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result /= rhs;       // Forward to /=()
	return result;
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument { "Divide by zero." };
	}
	set(getValue() / rhs.getValue());
	return *this;
}

bool SpreadsheetCell::operator==(double rhs) const
{
	return getValue() == rhs;
}

std::partial_ordering SpreadsheetCell::operator<=>(double rhs) const
{
	return getValue() <=> rhs;
}
